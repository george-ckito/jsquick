
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildUnavailable,
    once: false,
    run: async (parameter) => {
        console.log("Event guildUnavailable Triggered");
    },
};
