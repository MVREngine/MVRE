#ifndef V_WINDOW_
#define V_WINDOW_

#include <MVRE/graphics/backend/template/window.hpp>
#include <vulkan/vulkan.h>

namespace mvre_graphics {
    class v_instance;

    class v_window : public window {
    private:
        v_instance* m_instance = nullptr;
        VkSurfaceKHR m_surface = nullptr;
    public:
        VkSurfaceKHR raw_surface() const { return m_surface; }

        void initialize(const std::string &_title, mvre_math::vector2<int> _size) override;
        void create_surface(v_instance* _instance);
        void destroy_surface();
    };
}

#endif