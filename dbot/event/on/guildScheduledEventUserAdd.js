
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildScheduledEventUserAdd,
    once: false,
    run: async (parameter) => {
        console.log("Event guildScheduledEventUserAdd Triggered");
    },
};
