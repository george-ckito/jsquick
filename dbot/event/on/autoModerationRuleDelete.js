
const { Events } = require("discord.js");

module.exports = {
    event: Events.AutoModerationRuleDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event autoModerationRuleDelete Triggered");
    },
};
