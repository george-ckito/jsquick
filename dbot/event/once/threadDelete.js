const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ThreadDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event threadDelete Triggered);
    },
};
  