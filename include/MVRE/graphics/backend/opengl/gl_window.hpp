#ifndef MVRE_GL_WINDOW_
#define MVRE_GL_WINDOW_

#include <MVRE/graphics/backend/template/window.hpp>

namespace mvre_graphics {

    class gl_window : public window {
    public:
        void initialize(const std::string &_title, mvre_math::vector2<int> _size) override;
    };
}

#endif