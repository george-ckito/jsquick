//
// Created by georgeckito on 8/6/2024.
//

#include "Route.h"

#include <fstream>
#include <iomanip>

#include "Project.h"
#include "Log/Log.h"

namespace particle {
    std::string Route::getName() {
        return this->name;
    }
    void Route::setName(const std::string &name) {
        this->name = name;
    }
    std::string Route::getPath() {
        return this->path;
    }
    void Route::setPath(const std::string &path) {
        this->path = path;
    }
    nlohmann::json Route::getProject() {
        return this->project;
    }
    void Route::setProject(const nlohmann::json &project) {
        this->project = project;
    }
    Route::Route(const std::string &name, const std::string &path, const nlohmann::json &project) {
        this->name = name;
        this->path = path;
        this->project = project;
    }
    void Route::create() {
        if(this->project["type"] != project::projectType::API) {
            Log::logError("Route can only be created in an API project");
            return;
        }
        if(this->project["routes"][name]) {
            Log::logError("Route already exists!");
            return;
        }
        std::string path = this->project["path"];
        std::string file[] = {
            "const { Router } = require(\"express\");",
            "const " + name + " = Router();",
            "",
            name + ".get(\"/\", (req, res) => {",
            "   res.send(\"Succesfully created the route - " + name + "\");",
            "});",
            "",
            "module.exports = {",
            "   path: \"" + path + "\",",
            "   router: " + name + ",",
            "};"
        };
        std::ofstream route(path + "\\routes\\" + name + ".js");
        for (const auto& line: file) {
            route << line << std::endl;
        }
        route.close();
        this->project["routes"][name] = ".\\routes\\" + name + ".js";
        std::ofstream jsquick(path + "\\.jsquick");
        jsquick << std::setw(4) << this->project;
        jsquick.close();
        Log::logSUCC("Succesfully created the route file!");
        std::string text = "Modify .\\routes\\" + name + ".js" + " to finish your route!";
        Log::logInfo(text);

    }

} // particle