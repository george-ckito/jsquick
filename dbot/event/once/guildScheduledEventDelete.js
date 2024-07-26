const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildScheduledEventDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event guildScheduledEventDelete Triggered);
    },
};
  