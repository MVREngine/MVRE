#include <MVRE/resources/resource_manager.hpp>
#include <fstream>

using namespace mvre_resources;
using namespace mvre_graphics;
using namespace pl;

safe_map<std::string, resource_base*> resource_manager::resources;

std::map<MVRE_RESOURCE_TYPE, std::string> resource_manager::resources_locations = {
        { MVRE_RESOURCE_TYPE_SHADER, "engine/assets/shaders/" },
        { MVRE_RESOURCE_TYPE_TEXTURE, "engine/assets/textures/" }
};

bool resource_manager::read_file(const std::string& _path, std::vector<std::string>& data) {
    std::ifstream stream(_path.c_str());

    if (!stream.is_open())
        return false;

    std::string line;
    while (std::getline(stream, line))
        data.push_back(line);

    stream.close();

    return true;
}

bool resource_manager::read_binary(const std::string& _path, std::vector<char>& data) {
    std::ifstream stream(_path.c_str(), std::ios::ate | std::ios::binary);

    if (!stream.is_open())
        return false;

    size_t file_size = (size_t)stream.tellg();
    data.resize(file_size);

    stream.seekg(0);
    stream.read(data.data(), file_size);

    stream.close();

    return true;
}

std::string resource_manager::find_path(const std::string& _file, mvre_graphics::MVRE_RESOURCE_TYPE _type) {
    return resources_locations[_type] + _file;
}

void resource_manager::clean() {
    for (auto& kv : resources) {
        kv.second->clean();
        delete kv.second;
    }

    resources.clear();
    resources_locations.clear();
}