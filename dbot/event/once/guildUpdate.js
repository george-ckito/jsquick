const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildUpdate Triggered);
    },
};
  