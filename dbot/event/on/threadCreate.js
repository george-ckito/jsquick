
const { Events } = require("discord.js");

module.exports = {
    event: Events.ThreadCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event threadCreate Triggered");
    },
};
