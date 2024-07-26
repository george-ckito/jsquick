//
// Created by georgeckito on 7/19/2024.
//

#ifndef INPUT_H
#define INPUT_H
#include <string>

namespace Input {
    struct api {
        std::string name;
        std::string description;
        int port;
        bool mongo;
        std::string mongodb;
        bool git;
    };
    struct react {
        std::string name;
        std::string description;
        bool git;

    };
    struct dbot {
        std::string name;
        std::string description;
        bool mongo;
        std::string mongodb;
        std::string token;
        std::string client;
        std::string devGuild;
        bool git;
    };
    api inputAPI();
    react inputReact();
    dbot inputDbot();

} // Input

#endif //INPUT_H
