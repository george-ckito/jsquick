
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildAuditLogEntryCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildAuditLogEntryCreate Triggered");
    },
};
