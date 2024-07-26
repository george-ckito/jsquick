const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildMemberRemove,
    once: true,
    run: async (parameter) => {
        console.log(Event guildMemberRemove Triggered);
    },
};
  