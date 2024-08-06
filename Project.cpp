//
// Created by georgeckito on 8/5/2024.
//

#include "Project.h"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "windows.h"
#include "Log/Log.h"

namespace project {
    std::string Project::getPath() {
        return this->path;
    }
    void Project::setPath(const std::string& path) {
        this->path = path;
    }
    projectType Project::getType() {
        return this->type;
    }
    void Project::setType(projectType type) {
        this->type = type;
    }
    std::string Project::getSrcDir() {
        return this->srcDir;
    }
    void Project::setSrcDir(const std::string& srcDir) {
        this->srcDir = srcDir;
    }
    std::vector<std::string> Project::getFiles() {
        return this->files;
    }
    void Project::setFiles(const std::vector<std::string>& files) {
        this->files = files;
    }
    std::vector<std::string> Project::getFolders() {
        return this->folders;
    }
    void Project::setFolders(const std::vector<std::string>& folders) {
        this->folders = folders;
    }
    std::string Project::getEnv() {
        return this->env;
    }
    void Project::setEnv(const std::string& env) {
        this->env = env;
    }
    nlohmann::json Project::getJsquick() {
        return this->jsquick;
    }
    void Project::setJsquick(const nlohmann::json& jsquick) {
        this->jsquick = jsquick;
    }
    std::string Project::getPackages() {
        return this->packages;
    }
    void Project::setPackages(const std::string& packages) {
        this->packages = packages;
    }
    nlohmann::json Project::getPkg() {
        return this->pkg;
    }
    void Project::setPkg(const nlohmann::json& pkg) {
        this->pkg = pkg;
    }
    bool Project::getGit() {
        return this->git;
    }
    void Project::setGit(const bool &git) {
        this->git = git;
    }


    void Project::createFiles() {
        for(const auto& file : this->files) {
            const std::string src = this->srcDir + file;
            const std::string dest = this->path + file;
            Utility::copyFile(src, dest);
        }
        if(this->env != "") {
            try {
                std::ofstream envFile(this->getPath() + "\\.env");
                envFile << this->getEnv();
                envFile.close();
            } catch (const std::exception& e) {
                Log::logError(e.what());
            }
        }
    }
    void Project::createFolders() {
        for(const auto& folder : this->folders) {
            const std::string dest = this->path + folder;
            CreateDirectory(dest.c_str(), nullptr);
        }
    }
    void Project::createJsquick() {
        const std::string jsquickFile = this->path + "\\.jsquick";
        std::ofstream jsquick(jsquickFile);
        jsquick << std::setw(4) << this->jsquick << std::endl;
        jsquick.close();
        Log::logSUCC("Created the files");
        Log::logWarn("Don't modify the .jsquick file");
        Log::logInfo("Installing Packages...");
    }
    void Project::createPackage() {
        std::ofstream package(this->path + "\\package.json");
        package << std::setw(4) << this->pkg << std::endl;
        package.close();
    }
    void Project::installPackages() {
        const std::string cmd = "cd " + this->path + " && npm install " + this->packages;
        int result = std::system(cmd.c_str());
        if(result == 0) {
            Log::logSUCC("Installed packages");
        } else {
            Log::logError("Could not install packages");
        }

    }
    void Project::initGit() {
        std::string cmd = "cd /d " + this->path + " && git init";
        int result = std::system(cmd.c_str());
        if(result == 0) {
            Log::logSUCC("Initialized git");
        } else {
            Log::logError("Could not initialize git");
        }
    }


    void Project::create() {
        this->createFolders();
        this->createFiles();
        this->createJsquick();
        this->createPackage();
        Log::logSUCC("Created the files");
        Log::logWarn("Don't modify the .jsquick file");
        Log::logInfo("Installing Packages...");
        this->installPackages();
        Log::logSUCC("Successfully installed packages");
        if(this->git) {
            this->initGit();
        }
        Log::logInfo("API Created!");
        std::cout << std::endl << "  Start with: " << std::endl;
        std::cout << "      cd " << this->getJsquick()["name"] << std::endl;
        std::cout << "      npm start" << std::endl << std::endl;
    }
} // project