//
// Created by georgeckito on 8/6/2024.
//

#ifndef COMMAND_H
#define COMMAND_H
#include "json.hpp"

namespace particle {

class Command {
private:
    nlohmann::json project;
    std::string name;
    std::string description;
public:
    std::string getName();
    void setName(const std::string& name);
    std::string getDescription();
    void setDescription(const std::string& description);
    nlohmann::json getProject();
    void setProject(const nlohmann::json& project);
    void create();
    explicit Command(const std::string& name, const std::string& description, const nlohmann::json& project);
};

} // particle

#endif //COMMAND_H
