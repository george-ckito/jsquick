
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildMembersChunk,
    once: false,
    run: async (parameter) => {
        console.log("Event guildMembersChunk Triggered");
    },
};
