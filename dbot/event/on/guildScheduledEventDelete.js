
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildScheduledEventDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event guildScheduledEventDelete Triggered");
    },
};
