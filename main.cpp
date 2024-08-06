#include <iostream>

#include "API.h"
#include "args.hxx"
#include "Command.h"
#include "Component.h"
#include "DiscordBot.h"
#include "inquirer.h"
#include "React.h"
#include "Route.h"
#include "Create/Create.h"
#include "Input/Input.h"
#include "Log/Log.h"
#include "List/List.h"
#include "New/New.h"

int main(int argc, char *argv[])
{
    args::ArgumentParser parser("jsquick - A tool to help with JS project management.", "Try 'jsquick help' for more information.");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});

    args::Command create(parser, "create", "Create a new project");
    args::Command newCmd(parser, "new", "Create a new particle of a project");
    args::Command list(parser, "list", "List particules of a project");

    args::Group createGroup(create, "Project creation options");
    args::Flag react(createGroup, "react", "Create a React website project", {"react"});
    args::Flag api(createGroup, "api", "Create an API project", {"api"});
    args::Flag dbot(createGroup, "dbot", "Create a Discord bot project", {"dbot"});

    args::Group newGroup(newCmd, "New particle creation options");
    args::Flag route(newGroup, "route", "Create a new API route", {"route"});
    args::Flag component(newGroup, "component", "Create a new React component", {"component"});
    args::Flag command(newGroup, "command", "Create a new Discord bot command", {"command"});
    args::Flag event(newGroup, "event", "Create a new Discord bot event", {"event"});

    args::Group listGroup(list, "List particules of a project");
    args::Flag routes(listGroup, "routes", "List API routes", {"routes"});
    args::Flag components(listGroup, "components", "List React components", {"components"});
    args::Flag commands(listGroup, "commands", "List Discord bot commands", {"commands"});
    args::Flag events(listGroup, "events", "List Discord bot events", {"events"});

    try {
        parser.ParseCLI(argc, argv);
    } catch (args::Help) {
        std::cout << parser;
        return 0;
    } catch (args::ParseError e) {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    } catch (args::ValidationError e) {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }

    if (create) {
        Log::logTitle();
        if (react) {
            Input::react React = Input::inputReact();
            project::React project(React);
            project.create();
        } else if (api) {
            Input::api API = Input::inputAPI();
            project::api project(API);
            project.create();
        } else if (dbot) {
            Input::dbot Dbot = Input::inputDbot();
            project::DiscordBot project(Dbot);
            project.create();
        } else {
            Log::logError("Unknown project type!");
        }
    } else if (newCmd) {
        Log::logTitle();
        if (route) {
            particle::Route proute("", "", nlohmann::json());
        } else if (component) {
            particle::Component pcomponent("", "", nlohmann::json());
        } else if (command) {
            particle::Command pcommand("", "", nlohmann::json());
        } else if (event) {
            // particle::Event pevent("", "", nlohmann::json());
        } else {
            Log::logError("Unknown particle type!");
        }
    } else if (list) {
        Log::logTitle();
        if (routes) {
            List::listRoutes();
        } else if (components) {
            List::listComponents();
        } else if (commands) {
            List::listCommands();
        } else if (events) {
            List::listEvents();
        } else {
            Log::logError("Unknown list type!");
        }
    } else if (argc == 1) {
        Log::logTitle();
        std::cout << "Try jsquick help";
    } else {
        Log::logError("Unknown argument, try - jsquick help");
    }

    return 0;
}
