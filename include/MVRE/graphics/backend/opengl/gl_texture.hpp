#ifndef MVRE_GL_TEXTURE_
#define MVRE_GL_TEXTURE_

#include <MVRE/graphics/backend/template/texture.hpp>
#include <glad/glad.h>

namespace mvre_graphics {

    class gl_texture : public texture{
    private:
        unsigned int m_texture_id = 0;
    public:
        using texture::texture;

        inline void bind() override { glActiveTexture(GL_TEXTURE0 + m_index); glBindTexture(GL_TEXTURE_2D, m_texture_id); }
        inline void unbind() override { glBindTexture(GL_TEXTURE_2D, 0);  }

        bool load_resource(const std::string &_texture_path) override;
        void clean() override;
    };
}

#endif