
const { Events } = require("discord.js");

module.exports = {
    event: Events.ThreadDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event threadDelete Triggered");
    },
};
