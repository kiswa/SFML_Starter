#include "state_machine.hpp"

namespace kg {
    void StateMachine::startState(StateRef newState, bool isReplacing) {
        if (!_states.empty()) {
            if (isReplacing) {
                _states.pop();
            } else {
                _states.top()->pause();
            }
        }

        _states.push(std::move(newState));
        _states.top()->start();
    }

    void StateMachine::exitState() {
        if (_states.empty()) return;

        _states.pop();
        if (!_states.empty()) {
            _states.top()->resume();
        }
    }
}
