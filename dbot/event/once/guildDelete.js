const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event guildDelete Triggered);
    },
};
  