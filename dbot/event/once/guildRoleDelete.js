const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildRoleDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event guildRoleDelete Triggered);
    },
};
  