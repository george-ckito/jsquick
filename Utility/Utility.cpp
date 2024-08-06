//
// Created by georgeckito on 8/3/2024.
//
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <iostream>
#include "Utility.h"

#include "../json.hpp"
#include "../Log/Log.h"

namespace Utility {
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
    std::string toLower(std::string str) {
        std::string result = "";
        for (char ch : str) {
            // Convert each character to lowercase using tolower
            result += tolower(ch);
        }
        return result;
    }
    nlohmann::json getJsQuick(const std::string& path) {
        std::ifstream file(path + "\\.jsquick");
        nlohmann::json jsquick;
        if (file.good()) {
            file >> jsquick;
        } else {
            Log::logError("Error opening jsquick, are you in a project directory?");
        }
        file.close();
        return jsquick;
    }
} // Utility