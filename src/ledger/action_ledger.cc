#include "action_ledger.h"
#include <absl/status/status.h>
#include <absl/synchronization/mutex.h>
#include <vector>

namespace ledger {
// addAction adds an action to the ledger.
absl::Status ActionLedger::addAction(const Action &action,
                                     const absl::Duration timeout)
    ABSL_EXCLUSIVE_LOCKS_REQUIRED(mutex_) {

  if (!mutex_.LockWhenWithTimeout(absl::Condition(
                                      +[](void *) { return true; }, nullptr),
                                  timeout)) {
    return absl::DeadlineExceededError("Failed to acquire lock");
  }

  actions_.push_back(action);
  mutex_.Unlock();
  return absl::OkStatus();
}

// getActions returns all actions in the ledger.
std::vector<Action> ActionLedger::getActions() const { return actions_; };
} // namespace ledger
