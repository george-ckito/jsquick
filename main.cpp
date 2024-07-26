#include <iostream>
#include <vector>
#include "inquirer.h"
#include "Create/Create.h"
#include "Input/Input.h"
#include "Log/Log.h"
#include <cstring>

#include "List/List.h"
#include "New/New.h"


int main(int argc, char *argv[])
{
    switch (argc) {
        case 1: {
            Log::logTitle();
            std::cout << "Try jsquick help";
            break;
        }
        case 2: {
            if (strcmp(argv[1], "help") == 0) {
                Log::logTitle();
                std::cout << "Use the following arguments:\n";
                std::cout << "      help - This text,\n";
                std::cout << "      create - Create a new project,\n";
                std::cout << "      new - Creates a new part of a project (only available if you're currently in a jsquick project).\n";
                std::cout << "\nTo learn more about an argument try jsquick help <arg>\n";
            } else if (strcmp(argv[1], "create") == 0) {
                Log::logTitle();
                auto inquirer = alx::Inquirer("Input Application");
                std::string choice = inquirer.add_question({ "type", "What kind of project do you want to build?",
                        std::vector<std::string>{ "React Website", "API", "Discord Bot" }}).ask();
                if(choice == "API") {
                    Input::api API =  Input::inputAPI();
                    Create::createAPI(API);
                } else if(choice == "React Website") {
                    Input::react React = Input::inputReact();
                    Create::createReact(React);
                } else if(choice == "Discord Bot") {
                    Input::dbot Dbot = Input::inputDbot();
                    Create::createDbot(Dbot);
                } else {
                    Log::logError("Unkown choice!");
                }
            } else if (strcmp(argv[1], "new") == 0) {
                std::cout << "See jsquick help new.";
            } else if (strcmp(argv[1], "list") == 0) {
                std::cout << "See jsquick help list.";
            } else {
                Log::logError("Unknown argument, try - jsquick help");
            }
            break;
        }
        case 3: {
            if (strcmp(argv[1], "help") == 0 and strcmp(argv[2], "create") == 0) {
                Log::logTitle();
                std::cout << "Creates a new Jsquick project\n";
            } else if (strcmp(argv[1], "help") == 0 and strcmp(argv[2], "new") == 0) {
                Log::logTitle();
                std::cout << "Creates a new part of the project depending on its type,\n";
                std::cout << "  React website - use jsquick new component To create a new component in your website.\n";
                std::cout << "  API - use jsquick new route To create a new route for your API";
                std::cout << "  Discord Bot - use either jsquick new event or jsquick new command to create a new event or a command in your bot.";

            } else if (strcmp(argv[1], "help") == 0 and strcmp(argv[2], "list") == 0) {
                Log::logTitle();
                std::cout << "Lists the parts of a project depending on its type,\n";
                std::cout << "  React website - use jsquick list components To list the components in your website.\n";
                std::cout << "  API - use jsquick list routes To list the routes of your API";
                std::cout << "  Discord Bot - use either jsquick list events or jsquick list commands to list the events or the commands of your bot.";

            }
            else if(strcmp(argv[1], "create") == 0 and strcmp(argv[2], "react") == 0) {
                Input::react react = Input::inputReact();
                Create::createReact(react);
            }
            else if(strcmp(argv[1], "create") == 0 and strcmp(argv[2], "api") == 0) {
                Input::api api = Input::inputAPI();
                Create::createAPI(api);
            }
            else if(strcmp(argv[1], "create") == 0 and strcmp(argv[2], "dbot") == 0) {
                Input::dbot dbot = Input::inputDbot();
                Create::createDbot(dbot);
            }
            else if (strcmp(argv[1], "new") == 0 and strcmp(argv[2], "route") == 0) {
                New::newRoute();
            } else if (strcmp(argv[1], "new") == 0 and strcmp(argv[2], "component") == 0) {
                New::newComponent();
            } else if (strcmp(argv[1], "new") == 0 and strcmp(argv[2], "command") == 0) {
                New::newCommand();
            } else if (strcmp(argv[1], "new") == 0 and strcmp(argv[2], "event") == 0) {
                New::newEvent();
            } else if (strcmp(argv[1], "list") == 0 and strcmp(argv[2], "routes") == 0) {
                List::listRoutes();
            } else if (strcmp(argv[1], "list") == 0 and strcmp(argv[2], "components") == 0) {
                List::listComponents();
            } else if (strcmp(argv[1], "list") == 0 and strcmp(argv[2], "commands") == 0) {
                List::listCommands();
            } else if (strcmp(argv[1], "list") == 0 and strcmp(argv[2], "events") == 0) {
                List::listEvents();
            } else {
                Log::logError("Unknown argument, try - jsquick help");
            }
            break;
        }
        default: {
            std::cout << "Too many arguments!";
        }
    }
    return 0;
}
