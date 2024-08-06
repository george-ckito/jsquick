//
// Created by georgeckito on 8/5/2024.
//

#include "Component.h"

#include <iomanip>

#include "fstream"
#include "Project.h"
#include "Log/Log.h"

namespace particle {
    nlohmann::json Component::getProject() {
        return this->project;
    }
    void Component::setProject(const nlohmann::json &project) {
        this->project = project;
    }
    std::string Component::getName() {
        return this->name;
    }
    void Component::setName(const std::string &name) {
        this->name = name;
    }
    Component::Component(const std::string& name, const nlohmann::json& project, const bool& attribute) {
        this->name = name;
        this->project = project;
        this->attribute = attribute;
    }
    void Component::create() {
        if(this->project["type"] != project::projectType::REACT) {
            Log::logError("Component can only be created in a React project");
            return;
        }
        if(this->project["components"][name]) {
            Log::logError("Component already exists!");
            return;
        }
        std::string att;
        attribute ? att = "className" : att = "id";
        std::string path = this->project["path"];
        std::string file[] = {
            "import React from \"react\";",
            "import \"./css/index.css\"",
            "",
            "const " + name + " () => {",
            "   return (",
            "       <div " + att + "=" + "\"" + Utility::toLower(name) + "\">",
            "       <h1>New Component Created Using Jsquick!</h1>",
            "     </div>",
            "   )",
            "};",
            "",
            "export default " + name + ";"
        };
        std::ofstream component(path + "\\src\\" + name + ".js");
        std::ofstream css(path + "\\src\\css\\" + Utility::toLower(name) + ".css");
        for (const auto& line: file) {
            component << line << std::endl;
        }
        component.close();
        attribute ? css << "." << Utility::toLower(name) << " {" << std::endl : css << "#" << Utility::toLower(name) << " {" << std::endl;
        css << "    " << std::endl;
        css << "}";
        css.close();
        this->project["components"][name] = ".\\src\\" + name + ".js";
        std::ofstream jsquick(path + "\\.jsquick");
        jsquick << std::setw(4) << this->project;
        jsquick.close();
        Log::logSUCC("Succesfully created the component and the css file!");
        std::string text = "Modify .\\src\\" + name + ".js" + " to finish your component!";
        std::string text1 = "Modify .\\src\\css\\" + Utility::toLower(name) + ".css" + " to style your component!";
        Log::logInfo(text);
        Log::logInfo(text);

    }




} // particle