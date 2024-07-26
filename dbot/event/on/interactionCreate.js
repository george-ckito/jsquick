
const { Events } = require("discord.js");

module.exports = {
    event: Events.InteractionCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event interactionCreate Triggered");
    },
};
