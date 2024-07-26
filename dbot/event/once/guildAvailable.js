const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildAvailable,
    once: true,
    run: async (parameter) => {
        console.log(Event guildAvailable Triggered);
    },
};
  