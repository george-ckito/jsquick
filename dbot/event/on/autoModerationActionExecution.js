
const { Events } = require("discord.js");

module.exports = {
    event: Events.AutoModerationActionExecution,
    once: false,
    run: async (parameter) => {
        console.log("Event autoModerationActionExecution Triggered");
    },
};
