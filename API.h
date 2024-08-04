//
// Created by georgeckito on 8/3/2024.
//

#ifndef API_H
#define API_H
#include <string>
#include <vector>

#include "json.hpp"
#include "Utility/Utility.h"

namespace project {

class API {
private:
    std::string path;
    std::string srcDir = Utility::getExecutableDir() + "\\api";
    std::vector<std::string> files = {
        "\\index.js",
        "\\routes\\example.js",
        "\\jsquick\\handleRoutes.js",
        "\\jsquick\\loadFiles.js",
        "\\jsquick\\log.js"
    };
    nlohmann::json jsquick;
public:
    API();
    std::string getPath();
    void setPath(std::string path);
    void create();
    void createFiles();
    void createFolders();
    void createJsquick();
    void createPackage();
    void installPackages();

};

} // project

#endif //API_H
