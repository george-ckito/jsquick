
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildScheduledEventCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildScheduledEventCreate Triggered");
    },
};
