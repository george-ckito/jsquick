
const { Events } = require("discord.js");

module.exports = {
    event: Events.MessageReactionRemoveEmoji,
    once: false,
    run: async (parameter) => {
        console.log("Event messageReactionRemoveEmoji Triggered");
    },
};
