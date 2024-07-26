
const { Events } = require("discord.js");

module.exports = {
    event: Events.AutoModerationRuleCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event autoModerationRuleCreate Triggered");
    },
};
