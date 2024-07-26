const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildScheduledEventUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildScheduledEventUpdate Triggered);
    },
};
  