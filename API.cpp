#include "API.h"
#include <fstream>
#include "Input/Input.h"
#include "Log/Log.h"

namespace project {
    std::string API::getMongodb() {
        return this->mongodb;
    }
    void API::setMongodb(const std::string& mongodb) {
        this->mongodb = mongodb;
    }

    void API::createENV() {
        try {
            std::ofstream envFile(this->getPath() + "\\.env");
            envFile << "PORT=" << this->getJsquick()["port"] << std::endl;
            if (this->getJsquick()["mongo"]) {
                envFile << "MONGODB=" << this->mongodb << std::endl;
            }
            envFile.close();
        } catch (const std::exception& e) {
            Log::logError(e.what());
        }
    }
    API::API(const Input::api& input) {
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
        nlohmann::json jsquick;
        jsquick["name"] = input.name;
        jsquick["type"] = projectType::API;
        jsquick["routes"]["example"] = ".\\routes\\example.js";
        jsquick["port"] = input.port;
        jsquick["mongo"] = input.mongo;
        this->setJsquick(jsquick);
        this->setPackages("console-log-colors cors dotenv express glob mongoose table");
    }



    // void API::createFolders() {
    //     const std::string routesPath = this->getPath() + "\\routes";
    //     const std::string jsquickPath = this->getPath() + "\\jsquick";
    //
    //     CreateDirectory(this->getPath().c_str(), nullptr);
    //     if(!Utility::isDirectoryEmpty(this->getPath())) {
    //         Log::logError("Directory is not empty");
    //         return;
    //     }
    //     CreateDirectory(routesPath.c_str(), nullptr);
    //     CreateDirectory(jsquickPath.c_str(), nullptr);
    // }

} // namespace project