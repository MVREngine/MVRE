#include <MVRE/graphics/backend/vulkan/v_backend/v_sync.hpp>
#include <MVRE/graphics/backend/vulkan/v_backend/v_device.hpp>

using namespace mvre_graphics;

void v_sync::create() {
    m_image_available.resize(graphics_instance()->max_frames());
    m_render_finished.resize(graphics_instance()->max_frames());
    m_inflight_fence.resize(graphics_instance()->max_frames());

    VkSemaphoreCreateInfo semaphore_info {
        .sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO
    };

    VkFenceCreateInfo fence_info {
        .sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
        .flags = VK_FENCE_CREATE_SIGNALED_BIT
    };

    for (size_t i = 0; i < m_image_available.size(); i++) {
        if (vkCreateSemaphore(graphics_instance()->device()->raw_device(), &semaphore_info, nullptr, &m_image_available[i]) != VK_SUCCESS ||
            vkCreateSemaphore(graphics_instance()->device()->raw_device(), &semaphore_info, nullptr, &m_render_finished[i]) != VK_SUCCESS ||
            vkCreateFence(graphics_instance()->device()->raw_device(), &fence_info, nullptr, &m_inflight_fence[i]) != VK_SUCCESS)
            mvre_debug::debug::error("MVRE - Vulkan - Failed to create semaphores");
    }
}

void v_sync::wait() {
    vkWaitForFences(graphics_instance()->device()->raw_device(), 1, &m_inflight_fence[graphics_instance()->current_frame()], VK_TRUE, UINT64_MAX);
}

void v_sync::destroy() {
    for (size_t i = 0; i < m_image_available.size(); i++) {
        vkDestroySemaphore(graphics_instance()->device()->raw_device(), m_image_available[i], nullptr);
        vkDestroySemaphore(graphics_instance()->device()->raw_device(), m_render_finished[i], nullptr);
        vkDestroyFence(graphics_instance()->device()->raw_device(), m_inflight_fence[i], nullptr);
    }
}