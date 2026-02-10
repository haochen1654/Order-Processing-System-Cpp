#ifndef CLIENT_H
#define CLIENT_H

#include <chrono>
#include <string>
#include <vector>

#include "absl/strings/string_view.h"
#include "action.h"
#include "problem.h"

// Client is a client for fetching and solving challenge test problems.
class Client {
public:
  Client(absl::string_view endpoint, absl::string_view auth)
      : endpoint(endpoint), auth(auth) {}

  // newProblem fetches a new test problem from the server. The URL also works
  // in a browser for convenience.
  Problem newProblem(const std::string &name, long seed = 0);

  // solve submits a sequence of actions and parameters as a solution to a test
  // problem. Returns test result.
  std::string solve(const std::string &testId, std::chrono::microseconds rate,
                    std::chrono::microseconds min,
                    std::chrono::microseconds max,
                    const std::vector<Action> &actions);

private:
  std::string endpoint;
  std::string auth;
};

#endif // CLIENT_H
