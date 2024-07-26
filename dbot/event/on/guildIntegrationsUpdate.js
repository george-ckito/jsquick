
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildIntegrationsUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildIntegrationsUpdate Triggered");
    },
};
