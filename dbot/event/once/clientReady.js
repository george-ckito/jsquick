const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ClientReady,
    once: true,
    run: async (parameter) => {
        console.log(Event clientReady Triggered);
    },
};
  