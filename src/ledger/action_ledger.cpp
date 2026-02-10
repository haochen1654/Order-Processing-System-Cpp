#include "action_ledger.h"
#include <absl/Status/status.h>
#include <absl/synchronization/mutex.h>
#include <vector>

// addAction adds an action to the ledger.
absl::Status ActionLedger::addAction(const Action &action)
    ABSL_EXCLUSIVE_LOCKS_REQUIRED(mutex_) {
  lock();
  actions_.push_back(action);
  unlock();
  return absl::OkStatus();
}

// getActions returns all actions in the ledger.
std::vector<Action> ActionLedger::getActions() const { return actions_; };

void ActionLedger::lock() ABSL_EXCLUSIVE_LOCK_FUNCTION(mutex_) {
  mutex_.Lock();
}

void ActionLedger::unlock() ABSL_UNLOCK_FUNCTION(mutex_) { mutex_.Unlock(); }
