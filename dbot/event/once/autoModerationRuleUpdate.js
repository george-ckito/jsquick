const { Events } = require("discord.js");
  
module.exports = {
    event: Events.AutoModerationRuleUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event autoModerationRuleUpdate Triggered);
    },
};
  