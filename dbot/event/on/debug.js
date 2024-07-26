
const { Events } = require("discord.js");

module.exports = {
    event: Events.Debug,
    once: false,
    run: async (parameter) => {
        console.log("Event debug Triggered");
    },
};
