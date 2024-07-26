
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildMemberAdd,
    once: false,
    run: async (parameter) => {
        console.log("Event guildMemberAdd Triggered");
    },
};
