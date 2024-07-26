const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildBanAdd,
    once: true,
    run: async (parameter) => {
        console.log(Event guildBanAdd Triggered);
    },
};
  