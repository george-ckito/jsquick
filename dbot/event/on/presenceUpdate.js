
const { Events } = require("discord.js");

module.exports = {
    event: Events.PresenceUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event presenceUpdate Triggered");
    },
};
