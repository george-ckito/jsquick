const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildMemberAvailable,
    once: true,
    run: async (parameter) => {
        console.log(Event guildMemberAvailable Triggered);
    },
};
  