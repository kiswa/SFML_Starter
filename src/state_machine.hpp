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

            void addState(StateRef newState, bool isReplacing = true);
            void removeState();
            void checkStates(); // Run at end of each game loop.

            StateRef& getActiveState();

        private:
            std::stack<StateRef> _states;
            bool _isRemoving;
    };
}

#endif // STATE_MACHINE_HPP
