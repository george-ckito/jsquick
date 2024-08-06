#include "API.h"
#include <fstream>
#include "Input/Input.h"
#include "Log/Log.h"

namespace project {
    std::string api::getMongodb() {
        return this->mongodb;
    }
    void api::setMongodb(const std::string& mongodb) {
        this->mongodb = mongodb;
    }
    api::api(const Input::api& input) {
        this->setType(projectType::API);
        this->setPath(Utility::getCurrentWorkingDirectory() + "\\" + input.name);
        this->setSrcDir(Utility::getExecutableDir() + "\\api");
        this->setFiles({
            "\\index.js",
            "\\routes\\example.js",
            "\\jsquick\\handleRoutes.js",
            "\\jsquick\\loadFiles.js",
            "\\jsquick\\log.js"
        });
        this->setFolders({
            "\\routes",
            "\\jsquick"
        });
        std::string str;
        str = "PORT=" + this->getJsquick()["port"];
        str = str + "\n";
        if (this->getJsquick()["mongo"]) {
            str = str + "MONGODB=" + this->mongodb + "\n";
        }
        this->setEnv(str);
        nlohmann::json jsquick;
        jsquick["name"] = input.name;
        jsquick["type"] = projectType::API;
        jsquick["routes"]["example"] = ".\\routes\\example.js";
        jsquick["port"] = input.port;
        jsquick["mongo"] = input.mongo;
        this->setJsquick(jsquick);
        nlohmann::json pkg;
        pkg["name"] = this->getJsquick()["name"];
        pkg["version"] = "1.0.0";
        pkg["description"] = "Generated by jsquick";
        pkg["main"] = "index.js";
        pkg["scripts"]["start"] = "node index.js";
        pkg["dependencies"]["express"] = "^4.17.1";
        this->setPkg(pkg);
        if(input.git) {
            this->initGit();
        }
        this->setPackages("console-log-colors cors dotenv express glob mongoose table");
    }


} // namespace project