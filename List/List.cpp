//
// Created by georgeckito on 7/26/2024.
//

#include "List.h"

#include <fstream>

#include "../json.hpp"
#include "../Create/Create.h"
#include "../Log/Log.h"
#include "../New/New.h"

namespace List {
    void listRoutes() {
        Log::logTitle();
        if(New::checkProject() != "API") {
            Log::logError("Not in an API Jsquick project!");
            return;
        }
        nlohmann::json jsquick;
        std::ifstream quickFin(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        quickFin >> jsquick;
        quickFin.close();
        nlohmann::json routes = jsquick["routes"];
        std::cout << "Routes\n";
        for (auto it = routes.begin(); it != routes.end(); ++it) {
            // std::string a = "  " + dye::light_yellow(it.key()) + "⟶ " + it.value();
            Log::logItem(it.key(), it.value());
        }

    }
    void listComponents() {
        Log::logTitle();
        if(New::checkProject() != "React") {
            Log::logError("Not in an React Jsquick project!");
            return;
        }
        nlohmann::json jsquick;
        std::ifstream quickFin(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        quickFin >> jsquick;
        quickFin.close();
        nlohmann::json components = jsquick["components"];
        std::cout << "Components\n";
        for (auto it = components.begin(); it != components.end(); ++it) {
            // std::string a = "  " + dye::light_yellow(it.key()) + "⟶ " + it.value();
            Log::logItem(it.key(), it.value());
        }
    }
    void listEvents() {
        Log::logTitle();
        if(New::checkProject() != "Dbot") {
            Log::logError("Not in an Discord Bot Jsquick project!");
            return;
        }
        nlohmann::json jsquick;
        std::ifstream quickFin(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        quickFin >> jsquick;
        quickFin.close();
        nlohmann::json events = jsquick["events"];
        std::cout << "Events\n";
        for (auto it = events.begin(); it != events.end(); ++it) {
            // std::string a = "  " + dye::light_yellow(it.key()) + "⟶ " + it.value();
            Log::logItem(it.key(), it.value());
        }
    }
    void listCommands() {
        Log::logTitle();
        if(New::checkProject() != "Dbot") {
            Log::logError("Not in an Discord Bot Jsquick project!");
            return;
        }
        nlohmann::json jsquick;
        std::ifstream quickFin(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        quickFin >> jsquick;
        quickFin.close();
        nlohmann::json cmds = jsquick["commands"];
        std::cout << "Commands\n";
        for (auto it = cmds.begin(); it != cmds.end(); ++it) {
            // std::string a = "  " + dye::light_yellow(it.key()) + "⟶ " + it.value();
            Log::logItem(it.key(), it.value());
        }
    }
} // List