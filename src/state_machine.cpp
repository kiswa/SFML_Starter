#include "state_machine.hpp"

namespace kg {
    void StateMachine::addState(StateRef newState, bool isReplacing) {
        _isAdding = true;
        _isReplacing = isReplacing;

        _newState = std::move(newState);
    }

    void StateMachine::removeState() {
        _isRemoving = true;
    }

    void StateMachine::processStateChanges() {
        if (_isRemoving && !_states.empty()) {
            _states.pop();

            if (!_states.empty()) {
                _states.top()->resume();
            }
            _isRemoving = false;
        }

        if (_isAdding) {
            if (!_states.empty()) {
                if (_isReplacing) {
                    _states.pop();
                } else {
                    _states.top()->pause();
                }
            }

            _states.push(std::move(_newState));
            _states.top()->init();
            _isAdding = false;
        }
    }

    StateRef& StateMachine::getActiveState() {
        return _states.top();
    }
}
