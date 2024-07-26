const { Events } = require("discord.js");
  
module.exports = {
    event: Events.AutoModerationRuleCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event autoModerationRuleCreate Triggered);
    },
};
  