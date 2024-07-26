
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildMemberUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildMemberUpdate Triggered");
    },
};
