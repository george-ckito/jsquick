//
// Created by georgeckito on 8/3/2024.
//

#ifndef UTILITY_H
#define UTILITY_H
#include <string>

namespace Utility {
    std::string getCurrentWorkingDirectory();
    std::string getExecutablePath();
    std::string getExecutableDir();
    bool isDirectoryEmpty(const std::string& directoryPath);
    bool fileExists(const std::string& path);
    bool copyFile(const std::string& sourcePath, const std::string& destPath);


} // Utility

#endif //UTILITY_H
