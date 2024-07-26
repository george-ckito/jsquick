const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessageCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event messageCreate Triggered);
    },
};
  