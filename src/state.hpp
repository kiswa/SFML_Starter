#ifndef STATE_HPP
#define STATE_HPP

#include <memory>

namespace kg {
    class State {
    public:
        virtual void init() = 0;

        virtual void pause() { }
        virtual void resume() { }

        virtual void handleInput() = 0;
        virtual void update(float dt) = 0;
        virtual void render(float dt) = 0;
    };
}

#endif // STATE_HPP
