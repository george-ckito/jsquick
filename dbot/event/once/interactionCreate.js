const { Events } = require("discord.js");
  
module.exports = {
    event: Events.InteractionCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event interactionCreate Triggered);
    },
};
  