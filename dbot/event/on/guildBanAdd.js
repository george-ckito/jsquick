
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildBanAdd,
    once: false,
    run: async (parameter) => {
        console.log("Event guildBanAdd Triggered");
    },
};
