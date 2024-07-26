const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessageReactionRemoveAll,
    once: true,
    run: async (parameter) => {
        console.log(Event messageReactionRemoveAll Triggered);
    },
};
  