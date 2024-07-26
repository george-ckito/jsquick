
const { Events } = require("discord.js");

module.exports = {
    event: Events.ThreadListSync,
    once: false,
    run: async (parameter) => {
        console.log("Event threadListSync Triggered");
    },
};
