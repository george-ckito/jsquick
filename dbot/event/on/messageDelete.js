
const { Events } = require("discord.js");

module.exports = {
    event: Events.MessageDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event messageDelete Triggered");
    },
};
