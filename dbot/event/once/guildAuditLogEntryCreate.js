const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildAuditLogEntryCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildAuditLogEntryCreate Triggered);
    },
};
  