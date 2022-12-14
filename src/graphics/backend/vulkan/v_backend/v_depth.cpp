#include <MVRE/graphics/backend/vulkan/v_backend/v_depth.hpp>
#include <MVRE/graphics/backend/vulkan/v_backend/v_device.hpp>

using namespace mvre_graphics;

VkFormat v_depth::find_supported_format(const std::vector<VkFormat>& _candidates, VkImageTiling _tiling, VkFormatFeatureFlags _features) {
    for (VkFormat format : _candidates) {
        VkFormatProperties props;
        vkGetPhysicalDeviceFormatProperties(graphics_instance()->device()->raw_physical_device(), format, &props);

        if ((_tiling == VK_IMAGE_TILING_LINEAR && (props.linearTilingFeatures & _features) == _features) || (_tiling == VK_IMAGE_TILING_OPTIMAL && (props.optimalTilingFeatures & _features) == _features))
            return format;
    }

    mvre_debug::debug::error("MVRE - Vulkan - Depth - Failed to find supported format");
}

VkFormat v_depth::find_depth_format() {
    return find_supported_format(
            { VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT },
            VK_IMAGE_TILING_OPTIMAL,
            VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT
    );
}


void v_depth::create() {
    image = new v_image(graphics_instance());
    image->set_format(find_depth_format());
    image->set_size(graphics_instance()->get_window()->size());
    image->set_usage(VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT);
    image->set_aspect_flag(VK_IMAGE_ASPECT_DEPTH_BIT);

    image->create_image();
    image->create_image_view();
}

void v_depth::destroy() {
    image->destroy();
    delete image;
}