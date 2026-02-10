#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include <chrono>
#include <iostream>
#include <signal.h>
#include <thread>

#include "client/client.h"

// -------- Flag definitions --------
ABSL_FLAG(std::string, endpoint, "https://api.cloudkitchens.com",
          "Problem server endpoint");

ABSL_FLAG(std::string, auth, "", "Authentication token");

ABSL_FLAG(std::string, name, "", "Problem name. Leave blank (optional)");

ABSL_FLAG(long, seed, 0, "Problem seed (random if zero)");

ABSL_FLAG(long, rate, 500, "Inverse order rate (milliseconds)");

ABSL_FLAG(long, min, 4, "Minimum pickup time (seconds)");

ABSL_FLAG(long, max, 8, "Maximum pickup time (seconds)");

void interrupted(int s) { std::quick_exit(1); }

int main(int argc, char **argv) {
  signal(SIGINT, interrupted);

  try {
    // Parse flags
    absl::ParseCommandLine(argc, argv);

    // Read flag values
    const auto rate = std::chrono::milliseconds(absl::GetFlag(FLAGS_rate));
    const auto min = std::chrono::seconds(absl::GetFlag(FLAGS_min));
    const auto max = std::chrono::seconds(absl::GetFlag(FLAGS_max));

    const std::string endpoint = absl::GetFlag(FLAGS_endpoint);
    const std::string auth = absl::GetFlag(FLAGS_auth);
    const std::string name = absl::GetFlag(FLAGS_name);
    const long seed = absl::GetFlag(FLAGS_seed);

    Client client(endpoint, auth);
    auto problem = client.newProblem(name, seed);

    // ------ Execution harness logic goes here ------
    std::vector<Action> actions;
    for (auto order : problem.orders) {
      std::cout << "Received: " << order << std::endl;

      actions.emplace_back(Action(std::chrono::steady_clock::now(), order.id,
                                  "place", "cooler"));

      std::this_thread::sleep_for(rate);
    }
    // ----------------------------------------------

    auto result = client.solve(problem.testId, rate, min, max, actions);
    std::cout << "Result: " << result << std::endl;

    return 0;

  } catch (const std::exception &e) {
    std::cout << "Simulation failed: " << e.what() << std::endl;
    return 1;
  }
}
