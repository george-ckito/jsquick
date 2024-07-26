
const { Events } = require("discord.js");

module.exports = {
    event: Events.TypingStart,
    once: false,
    run: async (parameter) => {
        console.log("Event typingStart Triggered");
    },
};
