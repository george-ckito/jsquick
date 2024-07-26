
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildRoleDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event guildRoleDelete Triggered");
    },
};
