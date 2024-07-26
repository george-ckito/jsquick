const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildMemberUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildMemberUpdate Triggered);
    },
};
  