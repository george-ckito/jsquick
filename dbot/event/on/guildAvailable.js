
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildAvailable,
    once: false,
    run: async (parameter) => {
        console.log("Event guildAvailable Triggered");
    },
};
