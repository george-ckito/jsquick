const { Events } = require("discord.js");
  
module.exports = {
    event: Events.AutoModerationActionExecution,
    once: true,
    run: async (parameter) => {
        console.log(Event autoModerationActionExecution Triggered);
    },
};
  