const { Events } = require("discord.js");
  
module.exports = {
    event: Events.Invalidated,
    once: true,
    run: async (parameter) => {
        console.log(Event invalidated Triggered);
    },
};
  