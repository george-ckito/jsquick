
const { Events } = require("discord.js");

module.exports = {
    event: Events.MessageCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event messageCreate Triggered");
    },
};
