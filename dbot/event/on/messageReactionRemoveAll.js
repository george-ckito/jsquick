
const { Events } = require("discord.js");

module.exports = {
    event: Events.MessageReactionRemoveAll,
    once: false,
    run: async (parameter) => {
        console.log("Event messageReactionRemoveAll Triggered");
    },
};
