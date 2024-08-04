//
// Created by georgeckito on 8/5/2024.
//

#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include <vector>

#include "json.hpp"
#include "Utility/Utility.h"

namespace project {

    enum projectType {
        API,
        React,
        Dbot
    };

class Project {
private:
    projectType type;
    std::string path;
    std::string srcDir;
    std::vector<std::string> files;
    std::vector<std::string> folders;
    nlohmann::json jsquick;
    std::string packages;
public:
    std::string getPath();
    void setPath(const std::string& path);
    projectType getType();
    void setType(projectType type);
    std::string getPackages();
    void setPackages(const std::string& packages);
    std::string getSrcDir();
    void setSrcDir(const std::string& srcDir);
    std::vector<std::string> getFiles();
    void setFiles(const std::vector<std::string>& files);
    std::vector<std::string> getFolders();
    void setFolders(const std::vector<std::string>& files);
    nlohmann::json getJsquick();
    void setJsquick(const nlohmann::json& jsquick);
    void create();
    void createFiles();
    void createFolders();
    void createJsquick();
    void createPackage();
    void installPackages();

};

} // project

#endif //PROJECT_H
