//
// Created by georgeckito on 7/25/2024.
//

#include "New.h"

#include <iomanip>
#include <iostream>
#include "windows.h"
#include "fstream"
#include "../json.hpp"
#include "../Create/Create.h"
#include "../inquirer.h"
#include "../Log/Log.h"

namespace New {


    std::vector<DiscordEvent> discordEvents = {
    DiscordEvent::ApplicationCommandPermissionsUpdate,
    DiscordEvent::AutoModerationActionExecution,
    DiscordEvent::AutoModerationRuleCreate,
    DiscordEvent::AutoModerationRuleDelete,
    DiscordEvent::AutoModerationRuleUpdate,
    DiscordEvent::CacheSweep,
    DiscordEvent::ChannelCreate,
    DiscordEvent::ChannelDelete,
    DiscordEvent::ChannelPinsUpdate,
    DiscordEvent::ChannelUpdate,
    DiscordEvent::ClientReady,
    DiscordEvent::Debug,
    DiscordEvent::EntitlementCreate,
    DiscordEvent::EntitlementUpdate,
    DiscordEvent::EntitlementDelete,
    DiscordEvent::Error,
    DiscordEvent::GuildAuditLogEntryCreate,
    DiscordEvent::GuildAvailable,
    DiscordEvent::GuildBanAdd,
    DiscordEvent::GuildBanRemove,
    DiscordEvent::GuildCreate,
    DiscordEvent::GuildDelete,
    DiscordEvent::GuildEmojiCreate,
    DiscordEvent::GuildEmojiDelete,
    DiscordEvent::GuildEmojiUpdate,
    DiscordEvent::GuildIntegrationsUpdate,
    DiscordEvent::GuildMemberAdd,
    DiscordEvent::GuildMemberAvailable,
    DiscordEvent::GuildMemberRemove,
    DiscordEvent::GuildMembersChunk,
    DiscordEvent::GuildMemberUpdate,
    DiscordEvent::GuildRoleCreate,
    DiscordEvent::GuildRoleDelete,
    DiscordEvent::GuildRoleUpdate,
    DiscordEvent::GuildScheduledEventCreate,
    DiscordEvent::GuildScheduledEventDelete,
    DiscordEvent::GuildScheduledEventUpdate,
    DiscordEvent::GuildScheduledEventUserAdd,
    DiscordEvent::GuildScheduledEventUserRemove,
    DiscordEvent::GuildStickerCreate,
    DiscordEvent::GuildStickerDelete,
    DiscordEvent::GuildStickerUpdate,
    DiscordEvent::GuildUnavailable,
    DiscordEvent::GuildUpdate,
    DiscordEvent::InteractionCreate,
    DiscordEvent::Invalidated,
    DiscordEvent::InviteCreate,
    DiscordEvent::InviteDelete,
    DiscordEvent::MessageBulkDelete,
    DiscordEvent::MessageCreate,
    DiscordEvent::MessageDelete,
    DiscordEvent::MessagePollVoteAdd,
    DiscordEvent::MessagePollVoteRemove,
    DiscordEvent::MessageReactionAdd,
    DiscordEvent::MessageReactionRemove,
    DiscordEvent::MessageReactionRemoveAll,
    DiscordEvent::MessageReactionRemoveEmoji,
    DiscordEvent::MessageUpdate,
    DiscordEvent::PresenceUpdate,
    DiscordEvent::Raw,
    DiscordEvent::ShardDisconnect,
    DiscordEvent::ShardError,
    DiscordEvent::ShardReady,
    DiscordEvent::ShardReconnecting,
    DiscordEvent::ShardResume,
    DiscordEvent::StageInstanceCreate,
    DiscordEvent::StageInstanceDelete,
    DiscordEvent::StageInstanceUpdate,
    DiscordEvent::ThreadCreate,
    DiscordEvent::ThreadDelete,
    DiscordEvent::ThreadListSync,
    DiscordEvent::ThreadMembersUpdate,
    DiscordEvent::ThreadMemberUpdate,
    DiscordEvent::ThreadUpdate,
    DiscordEvent::TypingStart,
    DiscordEvent::UserUpdate,
    DiscordEvent::VoiceServerUpdate,
    DiscordEvent::VoiceStateUpdate,
    DiscordEvent::Warn,
    DiscordEvent::WebhooksUpdate,
  };
    std::string lowerFirstLetter(const std::string& str) {
        if (str.empty()) {
            return str; // Return empty string as is
        }

        std::string result = str;
        result[0] = std::tolower(result[0]); // Capitalize the first letter
        return result;
    }
    std::string eventToString(DiscordEvent event) {
    switch(event) {
        case DiscordEvent::ApplicationCommandPermissionsUpdate: return "ApplicationCommandPermissionsUpdate";
case DiscordEvent::AutoModerationActionExecution: return "AutoModerationActionExecution";
case DiscordEvent::AutoModerationRuleCreate: return "AutoModerationRuleCreate";
case DiscordEvent::AutoModerationRuleDelete: return "AutoModerationRuleDelete";
case DiscordEvent::AutoModerationRuleUpdate: return "AutoModerationRuleUpdate";
case DiscordEvent::CacheSweep: return "CacheSweep";
case DiscordEvent::ChannelCreate: return "ChannelCreate";
case DiscordEvent::ChannelDelete: return "ChannelDelete";
case DiscordEvent::ChannelPinsUpdate: return "ChannelPinsUpdate";
case DiscordEvent::ChannelUpdate: return "ChannelUpdate";
case DiscordEvent::ClientReady: return "ClientReady";
case DiscordEvent::Debug: return "Debug";
case DiscordEvent::EntitlementCreate: return "EntitlementCreate";
case DiscordEvent::EntitlementUpdate: return "EntitlementUpdate";
case DiscordEvent::EntitlementDelete: return "EntitlementDelete";
case DiscordEvent::Error: return "Error";
case DiscordEvent::GuildAuditLogEntryCreate: return "GuildAuditLogEntryCreate";
case DiscordEvent::GuildAvailable: return "GuildAvailable";
case DiscordEvent::GuildBanAdd: return "GuildBanAdd";
case DiscordEvent::GuildBanRemove: return "GuildBanRemove";
case DiscordEvent::GuildCreate: return "GuildCreate";
case DiscordEvent::GuildDelete: return "GuildDelete";
case DiscordEvent::GuildEmojiCreate: return "GuildEmojiCreate";
case DiscordEvent::GuildEmojiDelete: return "GuildEmojiDelete";
case DiscordEvent::GuildEmojiUpdate: return "GuildEmojiUpdate";
case DiscordEvent::GuildIntegrationsUpdate: return "GuildIntegrationsUpdate";
case DiscordEvent::GuildMemberAdd: return "GuildMemberAdd";
case DiscordEvent::GuildMemberAvailable: return "GuildMemberAvailable";
case DiscordEvent::GuildMemberRemove: return "GuildMemberRemove";
case DiscordEvent::GuildMembersChunk: return "GuildMembersChunk";
case DiscordEvent::GuildMemberUpdate: return "GuildMemberUpdate";
case DiscordEvent::GuildRoleCreate: return "GuildRoleCreate";
case DiscordEvent::GuildRoleDelete: return "GuildRoleDelete";
case DiscordEvent::GuildRoleUpdate: return "GuildRoleUpdate";
case DiscordEvent::GuildScheduledEventCreate: return "GuildScheduledEventCreate";
case DiscordEvent::GuildScheduledEventDelete: return "GuildScheduledEventDelete";
case DiscordEvent::GuildScheduledEventUpdate: return "GuildScheduledEventUpdate";
case DiscordEvent::GuildScheduledEventUserAdd: return "GuildScheduledEventUserAdd";
case DiscordEvent::GuildScheduledEventUserRemove: return "GuildScheduledEventUserRemove";
case DiscordEvent::GuildStickerCreate: return "GuildStickerCreate";
case DiscordEvent::GuildStickerDelete: return "GuildStickerDelete";
case DiscordEvent::GuildStickerUpdate: return "GuildStickerUpdate";
case DiscordEvent::GuildUnavailable: return "GuildUnavailable";
case DiscordEvent::GuildUpdate: return "GuildUpdate";
case DiscordEvent::InteractionCreate: return "InteractionCreate";
case DiscordEvent::Invalidated: return "Invalidated";
case DiscordEvent::InviteCreate: return "InviteCreate";
case DiscordEvent::InviteDelete: return "InviteDelete";
case DiscordEvent::MessageBulkDelete: return "MessageBulkDelete";
case DiscordEvent::MessageCreate: return "MessageCreate";
case DiscordEvent::MessageDelete: return "MessageDelete";
case DiscordEvent::MessagePollVoteAdd: return "MessagePollVoteAdd";
case DiscordEvent::MessagePollVoteRemove: return "MessagePollVoteRemove";
case DiscordEvent::MessageReactionAdd: return "MessageReactionAdd";
case DiscordEvent::MessageReactionRemove: return "MessageReactionRemove";
case DiscordEvent::MessageReactionRemoveAll: return "MessageReactionRemoveAll";
case DiscordEvent::MessageReactionRemoveEmoji: return "MessageReactionRemoveEmoji";
case DiscordEvent::MessageUpdate: return "MessageUpdate";
case DiscordEvent::PresenceUpdate: return "PresenceUpdate";
case DiscordEvent::Raw: return "Raw";
case DiscordEvent::ShardDisconnect: return "ShardDisconnect";
case DiscordEvent::ShardError: return "ShardError";
case DiscordEvent::ShardReady: return "ShardReady";
case DiscordEvent::ShardReconnecting: return "ShardReconnecting";
case DiscordEvent::ShardResume: return "ShardResume";
case DiscordEvent::StageInstanceCreate: return "StageInstanceCreate";
case DiscordEvent::StageInstanceDelete: return "StageInstanceDelete";
case DiscordEvent::StageInstanceUpdate: return "StageInstanceUpdate";
case DiscordEvent::ThreadCreate: return "ThreadCreate";
case DiscordEvent::ThreadDelete: return "ThreadDelete";
case DiscordEvent::ThreadListSync: return "ThreadListSync";
case DiscordEvent::ThreadMembersUpdate: return "ThreadMembersUpdate";
case DiscordEvent::ThreadMemberUpdate: return "ThreadMemberUpdate";
case DiscordEvent::ThreadUpdate: return "ThreadUpdate";
case DiscordEvent::TypingStart: return "TypingStart";
case DiscordEvent::UserUpdate: return "UserUpdate";
case DiscordEvent::VoiceServerUpdate: return "VoiceServerUpdate";
case DiscordEvent::VoiceStateUpdate: return "VoiceStateUpdate";
case DiscordEvent::Warn: return "Warn";
case DiscordEvent::WebhooksUpdate: return "WebhooksUpdate";
        default: return "UnknownEvent";
    }
}
    std::string toLower(std::string str) {
        std::string result = "";
        for (char ch : str) {
            // Convert each character to lowercase using tolower
            result += tolower(ch);
        }
        return result;
    }
    std::string checkProject() {
        std::string configFile = Create::getCurrentWorkingDirectory() + "\\.jsquick";
        bool projectExist = Create::fileExists(configFile);
        if (!projectExist) return "";
        nlohmann::json jsquick;
        std::ifstream jsqk(configFile);
        jsqk >> jsquick;
        jsqk.close();
        return jsquick["type"];
    }
    std::string newRoute() {
        Log::logTitle();
        if(checkProject() != "API") {
            Log::logError("Not in an API Jsquick project!");
            return "";
        }
        nlohmann::json jsquick;
        std::ifstream quickFin(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        quickFin >> jsquick;
        quickFin.close();
        auto inquirer = alx::Inquirer("New Route");
        std::string name = inquirer.add_question({ "name", "What do you want to name the route? (ex: create)" }).ask();
        std::string path = inquirer.add_question({ "path", "What path is the route gonna be on? (ex: /create)" }).ask();
        std::string router[] = {
            "const { Router } = require(\"express\");",
            "const " + name + " = Router();",
            "",
            name + ".get(\"/\", (req, res) => {",
            "   res.send(\"Succesfully created the route - " + name + "\");",
            "});",
            "",
            "module.exports = {",
            "   path: \"" + path + "\",",
            "   router: " + name + ",",
            "};"
        };
        std::ofstream fout(Create::getCurrentWorkingDirectory() + "\\routes\\" + name + ".js");
        for (const std::string& line: router) {
            fout << line << std::endl;
        }
        fout.close();
        Log::logSUCC("Succesfully created the route file!");
        jsquick["routes"][name] = ".\\routes\\" + name + ".js";
        std::ofstream jsquickFout(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        std::string text = "Modify .\\routes\\" + name + ".js" + " to finish your route!";
        Log::logInfo(text);
        jsquickFout << std::setw(4) << jsquick;
        jsquickFout.close();
        return Create::getCurrentWorkingDirectory();

    }
    std::string newComponent() {
        Log::logTitle();
        if(checkProject() != "React") {
            Log::logError("Not in an React Jsquick project!");
            return "";
        }
        nlohmann::json jsquick;
        std::ifstream quickFin(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        quickFin >> jsquick;
        quickFin.close();
        auto inquirer = alx::Inquirer("New Component");
        std::string name = inquirer.add_question({ "name", "What do you want to name the component? (ex: Navbar)" }).ask();
        std::string attribute = inquirer.add_question({"attribute", "Do you want the jsx div to have a class or a ID?", std::vector<std::string>{ "Class", "ID"}}).ask();
        std::string att;
        if(attribute == "Class") {
            att = "className";
        } else {
            att = "id";
        }
        std::string file[] = {
            "import React from \"react\";",
            "import \"./css/index.css\"",
            "",
            "const " + name + " () => {",
            "   return (",
            "       <div " + att + "=" + "\"" + toLower(name) + "\">",
            "       <h1>New Component Created Using Jsquick!</h1>",
            "     </div>",
            "   )",
            "};",
            "",
            "export default " + name + ";"
        };
        std::ofstream fout(Create::getCurrentWorkingDirectory() + "\\src\\" + name + ".js");
        std::ofstream cssFout(Create::getCurrentWorkingDirectory() + "\\src\\css\\" + toLower(name) + ".css");
        for (const auto& line: file) {
            fout << line << std::endl;
        }
        fout.close();
        if(att == "className") {
            cssFout << "." << toLower(name) << " {" << std::endl;
        } else {
            cssFout << "#" << toLower(name) << " {" << std::endl;
        }
        cssFout << "    " << std::endl;
        cssFout << "}";
        cssFout.close();
        std::ofstream jsquickFout(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        Log::logSUCC("Succesfully created the component and the css file!");
        jsquick["components"][name] = ".\\src\\" + name + ".js";
        std::string text = "Modify .\\src\\" + name + ".js" + " to finish your component!";
        std::string text1 = "Modify .\\src\\css\\" + toLower(name) + ".css" + " to style your component!";
        Log::logInfo(text);
        Log::logInfo(text1);
        jsquickFout << std::setw(4) << jsquick;
        jsquickFout.close();
        return Create::getCurrentWorkingDirectory();
    }
    std::string newEvent() {
        Log::logTitle();
        if(checkProject() != "Dbot") {
            Log::logError("Not in an Discord Bot Jsquick project!");
            return "";
        }
        nlohmann::json jsquick;
        std::ifstream quickFin(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        quickFin >> jsquick;
        quickFin.close();
        std::vector<std::string> discordEventNames;
        for (const auto& event : discordEvents) {
            discordEventNames.push_back(eventToString(event));
        }
        auto inquirer = alx::Inquirer("New Event");
        std::string event = inquirer.add_question({ "event", "Select your event", discordEventNames }).ask();
        std::string onceStr = inquirer.add_question({ "once", "Should this event run once?", alx::Type::yesNo }).ask();
        bool once = false;
        if (onceStr == "yes") once = true;
        std::string path;
        if (once) {
            path = Create::getExecutableDir() + "\\dbot\\event\\once\\" + lowerFirstLetter(event) + ".js";
        } else {
            path = Create::getExecutableDir() + "\\dbot\\event\\on\\" + lowerFirstLetter(event) + ".js";
        }
        Create::copyFile(path, Create::getCurrentWorkingDirectory() + "\\events\\" + lowerFirstLetter(event) + ".js");
        Log::logSUCC("Succesfully created the event file");
        jsquick["events"][event] = ".\\events\\" + lowerFirstLetter(event) + ".js";
        Log::logInfo("Modify .\\events\\" + lowerFirstLetter(event) + ".js to finish the event!");
        std::ofstream fout(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        fout << std::setw(4) << jsquick;
        fout.close();
    }
    std::string newCommand() {
        Log::logTitle();
        if(checkProject() != "Dbot") {
            Log::logError("Not in an Discord Bot Jsquick project!");
            return "";
        }
        nlohmann::json jsquick;
        std::ifstream quickFin(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        quickFin >> jsquick;
        quickFin.close();
        auto inquirer = alx::Inquirer("New Event");
        std::string name = inquirer.add_question({ "name", "What should the command name be? (ex: help)"}).ask();
        std::string description = inquirer.add_question({ "description", "Describe your command"}).ask();
        std::string data[] = {
            "const { SlashCommandBuilder } = require(\"discord.js\");"
            "",
            "module.exports = {",
            "   data: new SlashCommandBuilder()",
            "     .setName(\"" + name + "\")",
            "     .setDescription(\"" + description + "\"),",
            "   async execute(interaction)",
            "       await interaction.reply(\"Finish up the command at /commands/" + name + ".js\")",
            "   },",
            "};"
        };
        std::ofstream fout(Create::getCurrentWorkingDirectory() + "\\commands\\" + name + ".js");
        for (auto line: data) {
            fout << line << std::endl;
        }
        fout.close();
        jsquick["commands"][name] = ".\\commands\\" + name + ".js";
        std::ofstream jsFout(Create::getCurrentWorkingDirectory() + "\\.jsquick");
        jsFout << std::setw(4) << jsquick;
        jsFout.close();
    }
} // New