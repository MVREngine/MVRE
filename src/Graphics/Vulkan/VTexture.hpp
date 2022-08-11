#ifndef __VTEXTURE__
#define __VTEXTURE__

#include "VTypes.hpp"
#include <string>

using namespace std;

class VBuffer;
class VDevice;
class VCommandBuffer;
class VPipeline;
class VShader;
class VDescriptorPool;

class VTexture {
public:
    VkSampler textureSampler;
    VkImageView imageView;
    VBuffer* buffer;
    VDevice* device;
    VmaAllocator allocator;

    VTexture(VDevice* device, VmaAllocator& allocator);
    void LoadTexture(string textureLocation);
    void Bind(VCommandBuffer* commandBuffer, VPipeline* pipeline);
};

#endif