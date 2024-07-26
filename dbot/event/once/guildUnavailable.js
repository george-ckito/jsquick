const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildUnavailable,
    once: true,
    run: async (parameter) => {
        console.log(Event guildUnavailable Triggered);
    },
};
  