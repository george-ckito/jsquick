
const { Events } = require("discord.js");

module.exports = {
    event: Events.ThreadUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event threadUpdate Triggered");
    },
};
