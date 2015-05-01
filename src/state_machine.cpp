#include "state_machine.hpp"

namespace kg {
    void StateMachine::startState(StateRef newState, bool isReplacing) {
        if (isReplacing && !_states.empty()) {
            _states.pop();
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
