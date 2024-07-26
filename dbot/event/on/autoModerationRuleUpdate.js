
const { Events } = require("discord.js");

module.exports = {
    event: Events.AutoModerationRuleUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event autoModerationRuleUpdate Triggered");
    },
};
