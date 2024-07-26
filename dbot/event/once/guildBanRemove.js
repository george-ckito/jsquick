const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildBanRemove,
    once: true,
    run: async (parameter) => {
        console.log(Event guildBanRemove Triggered);
    },
};
  