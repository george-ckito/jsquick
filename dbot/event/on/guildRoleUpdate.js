
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildRoleUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildRoleUpdate Triggered");
    },
};
