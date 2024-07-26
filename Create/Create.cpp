#include "Create.h"
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <iostream>
#include "../json.hpp"
#include "../Log/Log.h"

namespace Create {
    std::string getCurrentWorkingDirectory() {
        char buffer[MAX_PATH];
        if (GetCurrentDirectory(MAX_PATH, buffer)) {
            return buffer;
        } else {
            return "error";
        }
    }

    std::string getExecutablePath() {
        char buffer[MAX_PATH];
        DWORD size = GetModuleFileNameA(NULL, buffer, MAX_PATH);
        if (size == 0) {
            return "";
        }
        return std::string(buffer);
    }

    std::string getExecutableDir() {
        std::string execPath = getExecutablePath();
        std::string dirPath = execPath.substr(0, execPath.find_last_of("\\/"));

        // Remove one more directory level
        std::string parentDir = dirPath.substr(0, dirPath.find_last_of("\\/"));
        return parentDir;
    }
    bool isDirectoryEmpty(const std::string& directoryPath) {
        WIN32_FIND_DATA findFileData;
        HANDLE hFind = FindFirstFile((directoryPath + "\\*").c_str(), &findFileData);

        if (hFind == INVALID_HANDLE_VALUE) {
            std::cerr << "Error: Invalid directory handle or directory does not exist." << std::endl;
            return false;
        }

        bool isEmpty = true;
        do {
            if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
                isEmpty = false;
                break;
            }
        } while (FindNextFile(hFind, &findFileData) != 0);

        FindClose(hFind);
        return isEmpty;
    }



    bool fileExists(const std::string& path) {
        std::ifstream file(path);
        return file.good();
    }

    bool copyFile(const std::string& sourcePath, const std::string& destPath) {
        Log::logInfo("Creating " + destPath);
        try {
            std::ifstream fin(sourcePath, std::ios::binary);
            if (!fin) {
                Log::logError("Error opening source file: " + sourcePath);
                return false;
            }

            std::ofstream fout(destPath, std::ios::binary);
            if (!fout) {
                Log::logError("Error opening destination file: " + destPath);
                return false;
            }

            fout << fin.rdbuf();

            if (fin.fail()) {
                Log::logError("Error reading from source file: " + sourcePath);
                return false;
            }

            if (fout.fail()) {
                Log::logError("Error writing to destination file: " + destPath);
                return false;
            }
            fin.close();
            fout.close();
            return true;
        } catch (const std::exception& e) {
            Log::logError(std::string("Exception: ") + e.what());
            return false;
        }
    }

    std::string createAPI(Input::api dir) {
        std::string path = getCurrentWorkingDirectory() + "\\" + dir.name;
        std::string routesPath = path + "\\routes";
        std::string jsquickPath = path + "\\jsquick";
        std::string apiDir = getExecutableDir() + "\\api";

        CreateDirectory(path.c_str(), NULL);
        if(!isDirectoryEmpty(path)) {
            Log::logError("Directory is not empty");
            return "";
        }
        CreateDirectory(routesPath.c_str(), NULL);
        CreateDirectory(jsquickPath.c_str(), NULL);



        // Check if all source files exist before attempting to copy
        std::vector<std::string> filesToCopy = {
            "\\index.js",
            "\\routes\\example.js",
            "\\jsquick\\handleRoutes.js",
            "\\jsquick\\loadFiles.js",
            "\\jsquick\\log.js"
        };

        for (const std::string& file : filesToCopy) {
            std::string fullPath = apiDir + file;
            if (!fileExists(fullPath)) {
                Log::logError("Source file does not exist: " + fullPath);
                return "";
            }
        }

        // Create index.js
        if (!copyFile(apiDir + "\\index.js", path + "\\index.js")) {
            Log::logError("Failed to copy index.js");
            return "";
        }

        // Create .jsquick file
        try {
            std::ofstream jsquickFout(path + "\\.jsquick");
            nlohmann::json jsquick;
            jsquick["name"] = dir.name;
            jsquick["type"] = "API";
            jsquick["routes"]["example"] = ".\\routes\\example.js";
            jsquick["port"] = dir.port;
            jsquickFout << std::setw(4) << jsquick << std::endl;
            jsquickFout.close();
        } catch (const std::exception& e) {
            Log::logError(e.what());
            return "";
        }

        // Create .env file
        try {
            std::ofstream envFile(path + "\\.env");
            envFile << "PORT=" << dir.port << std::endl;
            if (dir.mongo) {
                envFile << "MONGODB=" << dir.mongodb << std::endl;
            }
            envFile.close();
        } catch (const std::exception& e) {
            Log::logError(e.what());
            return "";
        }

        // Create package.json file
        try {
            std::ofstream pkgFout(path + "\\package.json");
            nlohmann::json pkgLock;
            pkgLock["name"] = dir.name;
            pkgLock["description"] = dir.description;
            pkgLock["version"] = "1.0.0";
            pkgLock["author"] = "";
            pkgLock["main"] = "index.js";
            pkgLock["license"] = "ISC";
            pkgLock["scripts"]["start"] = "node index.js";
            pkgFout << std::setw(4) << pkgLock << std::endl;
            pkgFout.close();
        } catch (const std::exception& e) {
            Log::logError(e.what());
            return "";
        }

        // Copy additional files
        if (!copyFile(apiDir + "\\routes\\example.js", path + "\\routes\\example.js")) {
            Log::logError("Failed to copy example.js");
            return "";
        }
        if (!copyFile(apiDir + "\\jsquick\\handleRoutes.js", path + "\\jsquick\\handleRoutes.js")) {
            Log::logError("Failed to copy handleRoutes.js");
            return "";
        }
        if (!copyFile(apiDir + "\\jsquick\\loadFiles.js", path + "\\jsquick\\loadFiles.js")) {
            Log::logError("Failed to copy loadFiles.js");
            return "";
        }
        if (!copyFile(apiDir + "\\jsquick\\log.js", path + "\\jsquick\\log.js")) {
            Log::logError("Failed to copy log.js");
            return "";
        }

        Log::logSUCC("Created the files");
        Log::logWarn("Don't modify the .jsquick file");
        Log::logInfo("Installing Packages...");

        // Run npm install
        std::string command = "cd /d " + path + " && npm install console-log-colors cors dotenv express glob mongoose table";
        int result = std::system(command.c_str());

        if (result != 0) {
            Log::logError("Failed installing packages, exit code " + std::to_string(result) + ". Is npm installed?");
            return "";
        } else {
            Log::logSUCC("Successfully installed packages");
        }

        if (dir.git) {
            std::string command1 = "cd /d " + path + " && git init";
            int result1 = std::system(command1.c_str());

            if (result1 != 0) {
                Log::logError("Failed initializing the repository, exit code " + std::to_string(result1) + ". Is git installed?");
                return "";
            }
            std::ofstream gitFout(path + "\\.gitignore");
            gitFout << "/node_modules/\n";
            gitFout << "/.env";
            gitFout.close();
            Log::logSUCC("Successfully Initialized Git");

        }

        Log::logInfo("API Created!");
        std::cout << std::endl << "  Start with: " << std::endl;
        std::cout << "      cd " << dir.name << std::endl;
        std::cout << "      npm start" << std::endl << std::endl;
        return path;

    }

    std::string createReact(Input::react dir) {
        std::string path = getCurrentWorkingDirectory() + "\\" + dir.name;
        std::string path1 = getCurrentWorkingDirectory() + "\\" + dir.name + "\\src";
        std::string path2 = getCurrentWorkingDirectory() + "\\" + dir.name + "\\public";
        std::string path3 = getCurrentWorkingDirectory() + "\\" + dir.name + "\\jsquick";
        std::string path4 = getCurrentWorkingDirectory() + "\\" + dir.name + "\\src\\css";
        std::string srcDir = getExecutableDir() + "\\react";

        CreateDirectory(path.c_str(), NULL);
        if(!isDirectoryEmpty(path)) {
            Log::logError(path + " is not empty");
            return "";
        }
        CreateDirectory(path1.c_str(), NULL);
        CreateDirectory(path2.c_str(), NULL);
        CreateDirectory(path3.c_str(), NULL);
        CreateDirectory(path4.c_str(), NULL);
        std::vector<std::string> files = {
            "\\webpack.config.js",
            "\\.babelrc",
            "\\jsquick\\index.js",
            "\\public\\index.html",
            "\\public\\react.svg",
            "\\public\\jsquick.png",
            "\\src\\App.js",
            "\\src\\css\\index.css",
        };

        for (const std::string& file : files) {
            std::string fullPath = srcDir + file;
            if (!fileExists(fullPath)) {
                Log::logError("Source file does not exist: " + fullPath);
                return "";
            }
            // Log::logInfo("Creating " + file);
            copyFile(fullPath, path + file);
        }

        

        //  .jsquick
        try {
            std::ofstream jsquickFout(path + "\\.jsquick");
            nlohmann::json jsquick;
            jsquick["name"] = dir.name;
            jsquick["type"] = "React";
            jsquick["components"]["App"] = ".\\src\\App.js";
            jsquickFout << std::setw(4) << jsquick;
            jsquickFout.close();
        } catch (const std::exception& e) {
            Log::logError(e.what());
            return "";
        }

        //  package.json
        std::ofstream pkgFout(path + "\\package.json");
        nlohmann::json pkg;
        pkg["name"] = dir.name;
        pkg["description"] = dir.description;
        pkg["main"] = "jsquick/index.js";
        pkg["license"] = "ISC";
        pkg["scripts"]["start"] = "webpack serve --mode development";
        pkg["scripts"]["build"] = "webpack --mode production";
        pkg["version"] = "1.0.0";
        pkgFout << std::setw(4) << pkg;
        pkgFout.close();

        Log::logSUCC("Created the files");
        Log::logWarn("Don't modify the .jsquick file");

        std::string installDeps = "cd /d " + path + " && npm install react react-dom";
        std::string installDevDeps = "cd /d " + path + " && npm install --save-dev webpack webpack-cli webpack-dev-server babel-loader @babel/core @babel/preset-env @babel/preset-react html-webpack-plugin css-loader style-loader";
        int resDeps = std::system(installDeps.c_str());
        int resDevDeps = std::system(installDevDeps.c_str());
        if(resDeps != 0 and resDevDeps != 0) {
            Log::logError("Failed installing dependencies");
            return "";
        }
        Log::logSUCC("Installed dependencies");

        if (dir.git) {
            std::string command1 = "cd /d " + path + " && git init";
            int result1 = std::system(command1.c_str());

            if (result1 != 0) {
                Log::logError("Failed initializing the repository, exit code " + std::to_string(result1) + ". Is git installed?");
                return "";
            }
            std::ofstream gitFout(path + "\\.gitignore");
            gitFout << "/node_modules/\n";
            gitFout << "/.env";
            gitFout.close();
            Log::logSUCC("Successfully Initialized Git");

        }
        Log::logInfo("Website Created!");
        std::cout << std::endl << "  Start with: " << std::endl;
        std::cout << "      cd " << dir.name << std::endl;
        std::cout << "      npm start" << std::endl << std::endl;
        return path;
    }

    std::string createDbot(Input::dbot dir) {
        std::string path = getCurrentWorkingDirectory() + "\\" + dir.name;
        std::string path1 = getCurrentWorkingDirectory() + "\\" + dir.name + "\\commands";
        std::string path2 = getCurrentWorkingDirectory() + "\\" + dir.name + "\\events";
        std::string path3 = getCurrentWorkingDirectory() + "\\" + dir.name + "\\jsquick";
        std::string path4 = getCurrentWorkingDirectory() + "\\" + dir.name + "\\jsquick\\handlers";
        std::string srcDir = getExecutableDir() + "\\dbot";
        CreateDirectory(path.c_str(), NULL);
        if(!isDirectoryEmpty(path)) {
            Log::logError(path + " is not empty");
            return "";
        }
        CreateDirectory(path1.c_str(), NULL);
        CreateDirectory(path2.c_str(), NULL);
        CreateDirectory(path3.c_str(), NULL);
        CreateDirectory(path4.c_str(), NULL);
        std::vector<std::string> files = {
            "\\index.js",
            "\\commands\\ping.js",
            "\\events\\ClientReady.js",
            "\\events\\InteractionCreate.js",
            "\\jsquick\\connectMongo.js",
            "\\jsquick\\deployCmds.js",
            "\\jsquick\\readFiles.js",
            "\\jsquick\\handlers\\cmdHandler.js",
            "\\jsquick\\handlers\\eventHandler.js"
        };
        for (const std::string& file : files) {
            std::string fullPath = srcDir + file;
            if (!fileExists(fullPath)) {
                Log::logError("Source file does not exist: " + fullPath);
                return "";
            }
            copyFile(fullPath, path + file);
        }

        //  package.json
        nlohmann::json pkg;
        pkg["name"] = dir.name;
        pkg["description"] = dir.description;
        pkg["version"] = "1.0.0";
        pkg["main"] = "index.js";
        pkg["scripts"]["start"] = "node index.js";
        pkg["license"] = "ISC";
        std::ofstream pkgFout(path + "\\package.json");
        pkgFout << std::setw(4) << pkg;
        pkgFout.close();

        //  .jsquick
        nlohmann::json jsquick;
        jsquick["type"] = "Dbot";
        jsquick["name"] = dir.name;
        jsquick["events"]["ClientReady"] = ".\\events\\ClientReady.js";
        jsquick["events"]["InteractionCreate"] = ".\\events\\InteractionCreate.js";
        jsquick["commands"]["ping"] = ".\\commands\\ping.js";
        jsquick["mongo"] = dir.mongo;
        std::ofstream jsquickFout(path + "\\.jsquick");
        jsquickFout << std::setw(4) << jsquick;
        jsquickFout.close();

        //  .env
        std::string lines[] = {"TOKEN=" + dir.token, "CLIENT=" + dir.client, "DEVGUILD=" + dir.devGuild};
        if(dir.mongo) {
            lines->append("MONGODB=" + dir.mongodb);
        }
        std::ofstream envFout(path + "\\.env");
        for (auto line : lines) {
            envFout << line << std::endl;
        }
        envFout.close();

        Log::logSUCC("Created the files");
        Log::logWarn("Don't modify the .jsquick file");
        std::string installDeps = "cd /d " + path + " && npm install discord.js dotenv fs mongoose path table";
        int resDeps = std::system(installDeps.c_str());
        if(resDeps != 0)  {
            Log::logError("Failed installing dependencies");
            return "";
        }
        Log::logSUCC("Installed dependencies");

        if (dir.git) {
            std::string command1 = "cd /d " + path + " && git init";
            int result1 = std::system(command1.c_str());

            if (result1 != 0) {
                Log::logError("Failed initializing the repository, exit code " + std::to_string(result1) + ". Is git installed?");
                return "";
            }
            std::ofstream gitFout(path + "\\.gitignore");
            gitFout << "/node_modules/\n";
            gitFout << "/.env";
            gitFout.close();
            Log::logSUCC("Successfully Initialized Git");
            Log::logInfo("Bot Created!");
            std::cout << std::endl << "  Start with: " << std::endl;
            std::cout << "      cd " << dir.name << std::endl;
            std::cout << "      npm start" << std::endl << std::endl;
            return path;
        }
    }
} // namespace Create
