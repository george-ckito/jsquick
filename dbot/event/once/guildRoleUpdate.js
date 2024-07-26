const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildRoleUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildRoleUpdate Triggered);
    },
};
  