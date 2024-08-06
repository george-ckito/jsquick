//
// Created by georgeckito on 8/6/2024.
//

#ifndef ROUTE_H
#define ROUTE_H
#include <string>

#include "json.hpp"

namespace particle {

class Route {
private:
    std::string name;
    std::string path;
    nlohmann::json project;
public:
    explicit Route(const std::string& name, const std::string& path, const nlohmann::json& project);
    std::string getName();
    void setName(const std::string& name);
    std::string getPath();
    void setPath(const std::string& path);
    nlohmann::json getProject();
    void setProject(const nlohmann::json& project);
    void create();
};

} // particle

#endif //ROUTE_H
