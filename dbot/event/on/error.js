
const { Events } = require("discord.js");

module.exports = {
    event: Events.Error,
    once: false,
    run: async (parameter) => {
        console.log("Event error Triggered");
    },
};
