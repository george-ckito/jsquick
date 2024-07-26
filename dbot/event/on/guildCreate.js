
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildCreate Triggered");
    },
};
