const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildMemberAdd,
    once: true,
    run: async (parameter) => {
        console.log(Event guildMemberAdd Triggered);
    },
};
  