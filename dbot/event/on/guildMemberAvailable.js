
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildMemberAvailable,
    once: false,
    run: async (parameter) => {
        console.log("Event guildMemberAvailable Triggered");
    },
};
