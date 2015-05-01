#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <memory>
#include <stack>

#include "state.hpp"

namespace kg {
    typedef std::unique_ptr<State> StateRef;

    class StateMachine {
        public:
            StateMachine() { }
            ~StateMachine() { }

            void startState(StateRef newState, bool isReplacing = true);
            void exitState();

        private:
            std::stack<StateRef> _states;
    };
}

#endif // STATE_MACHINE_HPP
