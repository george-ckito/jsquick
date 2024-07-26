
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event guildDelete Triggered");
    },
};
