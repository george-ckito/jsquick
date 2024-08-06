//
// Created by georgeckito on 8/5/2024.
//

#include "DiscordBot.h"

namespace project {
    std::string DiscordBot::getMongodb() {
        return this->mongodb;
    }
    void DiscordBot::setMongodb(const std::string &mongodb) {
        this->mongodb = mongodb;
    }
    std::string DiscordBot::getToken() {
        return this->token;
    }
    void DiscordBot::setToken(const std::string &token) {
        this->token = token;
    }
    std::string DiscordBot::getClientID() {
        return this->clientID;
    }
    void DiscordBot::setClientID(const std::string &id) {
        this->clientID = id;
    }
    std::string DiscordBot::getServerID() {
        return this ->serverID;
    }
    void DiscordBot::setServerID(const std::string &id) {
        this->serverID = id;
    }
    DiscordBot::DiscordBot(const Input::dbot &input) {
        this->setMongodb(input.mongodb);
        this->setToken(input.token);
        this->setClientID(input.client);
        this->setServerID(input.devGuild);
        this->setType(projectType::DBOT);
        this->setPath(Utility::getCurrentWorkingDirectory() + "\\" + input.name);
        this->setSrcDir(Utility::getExecutableDir() + "\\dbot");
        this->setFiles({
            "\\index.js",
            "\\commands\\ping.js",
            "\\events\\ClientReady.js",
            "\\events\\InteractionCreate.js",
            "\\jsquick\\connectMongo.js",
            "\\jsquick\\deployCmds.js",
            "\\jsquick\\readFiles.js",
            "\\jsquick\\handlers\\cmdHandler.js",
            "\\jsquick\\handlers\\eventHandler.js"
        });
        this->setFolders({
            "\\commands",
            "\\events",
            "\\jsquick",
            "\\jsquick\\handlers"
        });
        nlohmann::json jsquick;
        jsquick["type"] = projectType::DBOT;
        jsquick["name"] = input.name;
        jsquick["events"]["ClientReady"] = ".\\events\\ClientReady.js";
        jsquick["events"]["InteractionCreate"] = ".\\events\\InteractionCreate.js";
        jsquick["commands"]["ping"] = ".\\commands\\ping.js";
        jsquick["mongo"] = input.mongo;
        this->setJsquick(jsquick);
        nlohmann::json pkg;
        pkg["name"] = input.name;
        pkg["description"] = input.description;
        pkg["version"] = "1.0.0";
        pkg["main"] = "index.js";
        pkg["scripts"]["start"] = "node index.js";
        pkg["license"] = "ISC";
        this->setPkg(pkg);
        if(input.git) {
            this->initGit();
        }
        this->setPackages("discord.js dotenv fs mongoose path table");
    }









} // project