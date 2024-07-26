const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessageReactionAdd,
    once: true,
    run: async (parameter) => {
        console.log(Event messageReactionAdd Triggered);
    },
};
  