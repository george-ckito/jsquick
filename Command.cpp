//
// Created by georgeckito on 8/6/2024.
//

#include "Command.h"

#include <fstream>
#include <iomanip>

#include "Project.h"
#include "Log/Log.h"

namespace particle {
    std::string Command::getName() {
        return this->name;
    }
    void Command::setName(const std::string &name) {
        this->name = name;
    }
    std::string Command::getDescription() {
        return this->description;
    }
    void Command::setDescription(const std::string &description) {
        this->description = description;
    }
    nlohmann::json Command::getProject() {
        return this->project;
    }
    void Command::setProject(const nlohmann::json &project) {
        this->project = project;
    }
    Command::Command(const std::string &name, const std::string &description, const nlohmann::json &project) {
        this->name = name;
        this->description = description;
        this->project = project;
    }
    void Command::create() {
        if(this->project["type"] != project::projectType::DBOT) {
            Log::logError("Command can only be created in a Discord  Bot project");
            return;
        }
        if(this->project["commands"][this->name]) {
            Log::logError("Command already exists!");
            return;
        }
        std::string path = this->project["path"];
        std::string file[] = {
            "const { SlashCommandBuilder } = require(\"discord.js\");",
            "",
            "module.exports = {",
            "   data: new SlashCommandBuilder()",
            "     .setName(\"" + this->name + "\")",
            "     .setDescription(\"" + this->description + "\"),",
            "   async execute(interaction)",
            "       await interaction.reply(\"Finish up the command at /commands/" + name + ".js\")",
            "   },",
            "};"
        };
        std::ofstream command(path + "\\commands\\" + this->name + ".js");
        for(const std::string &line : file) {
            command << line << std::endl;
        }
        command.close();
        this->project["commands"][this->name] = ".\\commands\\" + name + ".js";
        std::ofstream jsquick(path + "\\.jsquick");
        jsquick << std::setw(4) << this->project;
        jsquick.close();
        Log::logSUCC("Succesfully created the command!");
        Log::logInfo("Finish up the command at /commands/" + name + ".js");

    }
} // particle