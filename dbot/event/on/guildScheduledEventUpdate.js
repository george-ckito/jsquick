
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildScheduledEventUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildScheduledEventUpdate Triggered");
    },
};
