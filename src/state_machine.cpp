#include "state_machine.hpp"

namespace kg {
    void StateMachine::addState(StateRef newState, bool isReplacing) {
        if (!_states.empty()) {
            if (isReplacing) {
                _states.pop();
            } else {
                _states.top()->pause();
            }
        }

        _states.push(std::move(newState));
        _states.top()->init();
    }

    void StateMachine::removeState() {
        _isRemoving = true;
    }

    void StateMachine::checkStates() {
        if (!_isRemoving || _states.empty()) return;

        _states.pop();
        if (!_states.empty()) {
            _states.top()->resume();
        }

        _isRemoving = false;
    }

    StateRef& StateMachine::getActiveState() {
        return _states.top();
    }
}
