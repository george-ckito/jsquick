
const { Events } = require("discord.js");

module.exports = {
    event: Events.EntitlementUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event entitlementUpdate Triggered");
    },
};
