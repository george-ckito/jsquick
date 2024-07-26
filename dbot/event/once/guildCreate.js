const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildCreate Triggered);
    },
};
  