
const { Events } = require("discord.js");

module.exports = {
    event: Events.InviteCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event inviteCreate Triggered");
    },
};
