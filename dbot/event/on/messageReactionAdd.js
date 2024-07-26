
const { Events } = require("discord.js");

module.exports = {
    event: Events.MessageReactionAdd,
    once: false,
    run: async (parameter) => {
        console.log("Event messageReactionAdd Triggered");
    },
};
