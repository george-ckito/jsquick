
const { Events } = require("discord.js");

module.exports = {
    event: Events.Raw,
    once: false,
    run: async (parameter) => {
        console.log("Event raw Triggered");
    },
};
