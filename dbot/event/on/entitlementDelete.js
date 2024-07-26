
const { Events } = require("discord.js");

module.exports = {
    event: Events.EntitlementDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event entitlementDelete Triggered");
    },
};
