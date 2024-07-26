const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessageReactionRemoveEmoji,
    once: true,
    run: async (parameter) => {
        console.log(Event messageReactionRemoveEmoji Triggered);
    },
};
  