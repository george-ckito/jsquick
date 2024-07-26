
const { Events } = require("discord.js");

module.exports = {
    event: Events.CacheSweep,
    once: false,
    run: async (parameter) => {
        console.log("Event cacheSweep Triggered");
    },
};
