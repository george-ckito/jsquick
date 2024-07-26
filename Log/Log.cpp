//
// Created by georgeckito on 7/19/2024.
//

#include "Log.h"

#include <iostream>

#include "../color.hpp"

namespace Log {
    void logItem(std::string name, std::string path) {
        std::cout << "  " << dye::light_yellow(name) << " -> " << path << std::endl;
    }
    void logTitle() {
        std::cout << dye::aqua("jsquick v1.0.0") << std::endl;
    }
    void logWarn(const std::string &text) {
        std::cout << dye::yellow("WARN") << " " << text << std::endl;
    }
    void logError(const std::string &text) {
        std::cout << dye::red("ERRO") << " " << text << std::endl;
    }
    void logInfo(const std::string &text) {
        std::cout << dye::blue("INFO") << " " << text << std::endl;
    }
    void logSUCC(const std::string &text) {
        std::cout << dye::green("SUCC") << " " << text << std::endl;
    }
}
