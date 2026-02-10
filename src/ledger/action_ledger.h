#ifndef ACTION_LEDGER_H
#define ACTION_LEDGER_H

#include "Action.h"
#include <absl/Status/status.h>
#include <absl/synchronization/mutex.h>
#include <vector>

class ActionLedger {
public:
  explicit ActionLedger(const std::vector<Action> &actions)
      : actions_(std::move(actions)){};

  // Default constructor
  ~ActionLedger(){};

  // Delete copy and move constructors and assignment operators
  ActionLedger(const ActionLedger &action_ledger) = delete;
  ActionLedger &operator=(const ActionLedger &action_ledger) = delete;
  ActionLedger(ActionLedger &&action_ledger) = delete;
  ActionLedger &operator=(ActionLedger &&action_ledger) = delete;

  // addAction adds an action to the ledger.
  absl::Status addAction(const Action &action)
      ABSL_EXCLUSIVE_LOCKS_REQUIRED(mutex_);

  // getActions returns all actions in the ledger.
  std::vector<Action> getActions() const;

  // lock the ledger for exclusive access. Must be paired with unlock().
  void lock() ABSL_EXCLUSIVE_LOCK_FUNCTION(mutex_);

  // unlock the ledger. Must be paired with lock().
  void unlock() ABSL_UNLOCK_FUNCTION(mutex_);

private:
  std::vector<Action> actions_ ABSL_GUARDED_BY(mutex_);
  absl::Mutex mutex_; // protects actions_
};

#endif // ACTION_LEDGER_H