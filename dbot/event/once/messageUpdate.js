const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessageUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event messageUpdate Triggered);
    },
};
  