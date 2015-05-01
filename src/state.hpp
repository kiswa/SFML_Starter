#ifndef STATE_HPP
#define STATE_HPP

#include <memory>

namespace sf {
    class RenderWindow;
}

namespace kg {
    class StateMachine;

    typedef std::shared_ptr<sf::RenderWindow> WindowRef;
    typedef std::shared_ptr<StateMachine> StateMachineRef;

    class State {
    public:
        virtual void start() = 0;
        virtual void pause() { }
        virtual void resume() { }

        virtual void handleInput() = 0;
        virtual void update(float dt) = 0;
        virtual void render(float dt) = 0;

    protected:
        WindowRef _window;
    };
}

#endif // STATE_HPP
