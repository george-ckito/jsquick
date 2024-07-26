
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildScheduledEventUserRemove,
    once: false,
    run: async (parameter) => {
        console.log("Event guildScheduledEventUserRemove Triggered");
    },
};
