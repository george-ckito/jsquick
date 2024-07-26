//
// Created by georgeckito on 7/25/2024.
//

#ifndef NEW_H
#define NEW_H
#include <iostream>
#include <vector>

namespace New {
    enum class DiscordEvent {
        ApplicationCommandPermissionsUpdate,
        AutoModerationActionExecution,
        AutoModerationRuleCreate,
        AutoModerationRuleDelete,
        AutoModerationRuleUpdate,
        CacheSweep,
        ChannelCreate,
        ChannelDelete,
        ChannelPinsUpdate,
        ChannelUpdate,
        ClientReady,
        Debug,
        EntitlementCreate,
        EntitlementUpdate,
        EntitlementDelete,
        Error,
        GuildAuditLogEntryCreate,
        GuildAvailable,
        GuildBanAdd,
        GuildBanRemove,
        GuildCreate,
        GuildDelete,
        GuildEmojiCreate,
        GuildEmojiDelete,
        GuildEmojiUpdate,
        GuildIntegrationsUpdate,
        GuildMemberAdd,
        GuildMemberAvailable,
        GuildMemberRemove,
        GuildMembersChunk,
        GuildMemberUpdate,
        GuildRoleCreate,
        GuildRoleDelete,
        GuildRoleUpdate,
        GuildScheduledEventCreate,
        GuildScheduledEventDelete,
        GuildScheduledEventUpdate,
        GuildScheduledEventUserAdd,
        GuildScheduledEventUserRemove,
        GuildStickerCreate,
        GuildStickerDelete,
        GuildStickerUpdate,
        GuildUnavailable,
        GuildUpdate,
        InteractionCreate,
        Invalidated,
        InviteCreate,
        InviteDelete,
        MessageBulkDelete,
        MessageCreate,
        MessageDelete,
        MessagePollVoteAdd,
        MessagePollVoteRemove,
        MessageReactionAdd,
        MessageReactionRemove,
        MessageReactionRemoveAll,
        MessageReactionRemoveEmoji,
        MessageUpdate,
        PresenceUpdate,
        Raw,
        ShardDisconnect,
        ShardError,
        ShardReady,
        ShardReconnecting,
        ShardResume,
        StageInstanceCreate,
        StageInstanceDelete,
        StageInstanceUpdate,
        ThreadCreate,
        ThreadDelete,
        ThreadListSync,
        ThreadMembersUpdate,
        ThreadMemberUpdate,
        ThreadUpdate,
        TypingStart,
        UserUpdate,
        VoiceServerUpdate,
        VoiceStateUpdate,
        Warn,
        WebhooksUpdate,
      };
    std::string lowerFirstLetter(const std::string& str);
    std::string eventToString(DiscordEvent event);
    std::string toLower(std::string str);
    std::string checkProject();
    std::string newRoute();
    std::string newComponent();
    std::string newEvent();
    std::string newCommand();

}   // New

#endif //NEW_H
