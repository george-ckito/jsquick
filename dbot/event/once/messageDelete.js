const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessageDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event messageDelete Triggered);
    },
};
  