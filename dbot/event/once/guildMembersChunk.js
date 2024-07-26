const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildMembersChunk,
    once: true,
    run: async (parameter) => {
        console.log(Event guildMembersChunk Triggered);
    },
};
  