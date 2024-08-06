//
// Created by georgeckito on 8/5/2024.
//

#ifndef DISCORDBOT_H
#define DISCORDBOT_H
#include "Project.h"
#include "Input/Input.h"

namespace project {

class DiscordBot : public Project {
private:
    std::string mongodb;
    std::string token;
    std::string clientID;
    std::string serverID;
public:
    std::string getMongodb();
    void setMongodb(const std::string& mongodb);
    std::string getToken();
    void setToken(const std::string& token);
    std::string getClientID();
    void setClientID(const std::string& id);
    std::string getServerID();
    void setServerID(const std::string& id);
    explicit DiscordBot(const Input::dbot& input);
};

} // project

#endif //DISCORDBOT_H
