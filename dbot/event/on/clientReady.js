
const { Events } = require("discord.js");

module.exports = {
    event: Events.ClientReady,
    once: false,
    run: async (parameter) => {
        console.log("Event clientReady Triggered");
    },
};
