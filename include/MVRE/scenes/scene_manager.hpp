#ifndef MVRE_SCENE_MANAGER_
#define MVRE_SCENE_MANAGER_

#include <string>
#include <pl/safe_map.hpp>

#include "scene.hpp"

namespace mvre_scenes {

    class scene_manager {
    private:
        static pl::safe_map<std::string, scene*> m_scenes;
    public:

        static void add_scene(std::string _scene_name, scene* _scene);
        static void load_scene(std::string _scene_name);
    };
}

#endif