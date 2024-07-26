
const { Events } = require("discord.js");

module.exports = {
    event: Events.MessageUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event messageUpdate Triggered");
    },
};
