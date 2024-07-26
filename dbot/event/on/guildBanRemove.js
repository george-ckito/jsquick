
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildBanRemove,
    once: false,
    run: async (parameter) => {
        console.log("Event guildBanRemove Triggered");
    },
};
