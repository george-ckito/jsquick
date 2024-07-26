
const { Events } = require("discord.js");

module.exports = {
    event: Events.InviteDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event inviteDelete Triggered");
    },
};
