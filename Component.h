//
// Created by georgeckito on 8/5/2024.
//

#ifndef COMPONENT_H
#define COMPONENT_H
#include "json.hpp"

namespace particle {

class Component {
private:
    nlohmann::json project;
    std::string name;
    bool attribute; // 0 - ID 1 - Class
public:
    explicit Component(const std::string& name, const nlohmann::json& project, const bool& attribute);
    nlohmann::json getProject();
    void setProject(const nlohmann::json& project);
    std::string getName();
    void setName(const std::string& name);
    void create();
};

} // particle

#endif //COMPONENT_H
