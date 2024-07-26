
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildRoleCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildRoleCreate Triggered");
    },
};
