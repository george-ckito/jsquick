const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildScheduledEventUserAdd,
    once: true,
    run: async (parameter) => {
        console.log(Event guildScheduledEventUserAdd Triggered);
    },
};
  