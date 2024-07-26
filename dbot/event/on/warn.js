
const { Events } = require("discord.js");

module.exports = {
    event: Events.Warn,
    once: false,
    run: async (parameter) => {
        console.log("Event warn Triggered");
    },
};
