const { Events } = require("discord.js");
  
module.exports = {
    event: Events.AutoModerationRuleDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event autoModerationRuleDelete Triggered);
    },
};
  