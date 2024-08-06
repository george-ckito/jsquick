//
// Created by georgeckito on 8/5/2024.
//

#include "React.h"

namespace project {
    React::React(const Input::api &input) {
        this->setType(projectType::REACT);
        this->setPath(Utility::getCurrentWorkingDirectory() + "\\" + input.name);
        this->setSrcDir(Utility::getExecutableDir() + "\\react");
        this->setFiles({
            "\\webpack.config.js",
            "\\.babelrc",
            "\\jsquick\\index.js",
            "\\public\\index.html",
            "\\public\\react.svg",
            "\\public\\jsquick.png",
            "\\src\\App.js",
            "\\src\\css\\index.css",
        });
        this->setFolders({
            "\\src",
            "\\public",
            "\\jsquick",
            "\\src\\css"
        });
        nlohmann::json jsquick;
        jsquick["name"] = input.name;
        jsquick["type"] = projectType::REACT;
        jsquick["components"]["App"] = ".\\src\\App.js";
        this->setJsquick(jsquick);
        nlohmann::json pkg;
        pkg["name"] = input.name;
        pkg["description"] = input.description;
        pkg["main"] = "jsquick/index.js";
        pkg["license"] = "ISC";
        pkg["scripts"]["start"]= "webpack serve --mode development";
        pkg["scripts"]["build"] = "webpack --mode production";
        pkg["version"] = "1.0.0";
        this->setPkg(pkg);
        if(input.git) {
            this->initGit();
        }
        this->setPackages("react react-dom webpack webpack-cli webpack-dev-server babel-loader @babel/core @babel/preset-env @babel/preset-react html-webpack-plugin css-loader style-loader");
    }

} // project