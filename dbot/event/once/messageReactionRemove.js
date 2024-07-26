const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessageReactionRemove,
    once: true,
    run: async (parameter) => {
        console.log(Event messageReactionRemove Triggered);
    },
};
  