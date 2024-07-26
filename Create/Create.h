//
// Created by georgeckito on 7/19/2024.
//

#ifndef CREATE_H
#define CREATE_H
#include <iostream>

#include "../Input/Input.h"

namespace Create {
    std::string createAPI(Input::api dir);
    std::string createReact(Input::react dir);
    std::string createDbot(Input::dbot dir);
    std::string getExecutablePath();
    std::string getCurrentWorkingDirectory();
    bool isDirectoryEmpty(const std::string& directoryPath);
    std::string getExecutableDir();
    bool fileExists(const std::string& path);
    bool copyFile(const std::string& sourcePath, const std::string& destPath);

} // Create

#endif //CREATE_H
