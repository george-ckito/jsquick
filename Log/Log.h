//
// Created by georgeckito on 7/19/2024.
//

#ifndef LOG_H
#define LOG_H
#include <string>

namespace Log {
    void logItem(std::string name, std::string path);
    void logTitle();
    void logWarn(const std::string &text);
    void logError(const std::string &text);
    void logInfo(const std::string &text);
    void logSUCC(const std::string &text);

} // Log

#endif //LOG_H
