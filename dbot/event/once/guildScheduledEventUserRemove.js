const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildScheduledEventUserRemove,
    once: true,
    run: async (parameter) => {
        console.log(Event guildScheduledEventUserRemove Triggered);
    },
};
  