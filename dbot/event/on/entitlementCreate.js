
const { Events } = require("discord.js");

module.exports = {
    event: Events.EntitlementCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event entitlementCreate Triggered");
    },
};
