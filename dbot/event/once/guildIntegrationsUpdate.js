const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildIntegrationsUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildIntegrationsUpdate Triggered);
    },
};
  