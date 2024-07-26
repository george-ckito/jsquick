
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildUpdate Triggered");
    },
};
