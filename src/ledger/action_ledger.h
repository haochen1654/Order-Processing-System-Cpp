#ifndef ACTION_LEDGER_H
#define ACTION_LEDGER_H

#include "action.h"
#include <absl/Status/status.h>
#include <absl/synchronization/mutex.h>
#include <absl/time/time.h>
#include <vector>

namespace ledger {
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
  absl::Status addAction(const Action &action, absl::Duration timeout)
      ABSL_LOCKS_EXCLUDED(mutex_);

  // getActions returns all actions in the ledger.
  std::vector<Action> getActions() const;

private:
  std::vector<Action> actions_ ABSL_GUARDED_BY(mutex_);
  absl::Mutex mutex_; // protects actions_
};
} // namespace ledger

#endif // ACTION_LEDGER_H