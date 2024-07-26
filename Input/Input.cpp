//
// Created by georgeckito on 7/19/2024.
//

#include "Input.h"

#include <string>
#include "../inquirer.h"
#include "../Log/Log.h"

namespace Input {
    // struct api {
    //     std::string name;
    //     std::string description;
    //     int port;
    //     bool mongo;
    //     std::string mongodb;
    //     bool git;
    // };

    api inputAPI() {
        auto inquirer = alx::Inquirer("API Info");
        std::string name = inquirer.add_question({ "name", "What do you want your API to be called?" }).ask();
        std::string description = inquirer.add_question({ "description", "Describe your project:" }).ask();
        int port = std::atoi(inquirer.add_question({ "port", "Which port should the API run on?", alx::Type::integer }).ask().c_str());
        std::string boolStr = inquirer.add_question({ "mongo", "Do you have a MongoDB database?", alx::Type::yesNo }).ask();
        bool mongo = false;
        if(boolStr == "yes") mongo = true;
        std::string mongodb;
        if (mongo) {
            mongodb = inquirer.add_question({ "mongodb", "What is your MongoDB's URI" }).ask();
        } else {
            mongodb = "";
        }
        std::string gitStr = inquirer.add_question({ "git", "Do you want to make this a Git Repository?", alx::Type::yesNo }).ask();
        bool git = false;
        if(gitStr == "yes") git = true;
        return api {
            name,
            description,
            port,
            mongo,
            mongodb,
            git
        };
    }
    // struct react {
    //     std::string name;
    //     std::string description;
    //     bool router;
    //     bool fontawesome;
    //     bool git;
    //
    // };
    react inputReact() {
        auto inquirer = alx::Inquirer("App Info");
        std::string name = inquirer.add_question({ "name", "What do you want your React website to be called?" }).ask();

        std::string description = inquirer.add_question({ "description", "Describe your website:" }).ask();

        std::string gitStr = inquirer.add_question({ "git", "Do you want to make this a Git Repository?", alx::Type::yesNo }).ask();
        bool git = false;
        if(gitStr == "yes") git = true;
        return react {
            name,
            description,
            git
        };

    }
    // struct dbot {
    //     std::string name;
    //     std::string description;
    //     bool mongo;
    //     std::string mongodb;
    //     std::string token;
    //     std::string client;
    //     std::string devGuild;
    //     bool git;
    // };
    dbot inputDbot() {
        auto inquirer = alx::Inquirer("Bot Info");
        std::string name = inquirer.add_question({ "name", "What is your bot's name?" }).ask();

        std::string description = inquirer.add_question({ "description", "Describe your bot:" }).ask();

        std::string boolStr = inquirer.add_question({ "mongo", "Do you have a MongoDB database?", alx::Type::yesNo }).ask();
        bool mongo = false;
        if(boolStr == "yes") mongo = true;
        std::string mongodb;
        if (mongo) {
            mongodb = inquirer.add_question({ "mongodb", "What is your MongoDB's URI" }).ask();
        } else {
            mongodb = "";
        }

        std::string token = inquirer.add_question({ "token", "Enter your bot's token"}).ask();
        std::string client = inquirer.add_question({ "client", "Enter your bot's Client ID"}).ask();
        std::string devGuild = inquirer.add_question({ "devGuild", "Enter your development server's ID"}).ask();
        std::string gitStr = inquirer.add_question({ "git", "Do you want to make this a Git Repository?", alx::Type::yesNo }).ask();
        bool git = false;
        if(gitStr == "yes") git = true;
        return dbot{
            name,
            description,
            mongo,
            mongodb,
            token,
            client,
            devGuild,
            git

        };
    }
} // Input