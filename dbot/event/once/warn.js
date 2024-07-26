const { Events } = require("discord.js");
  
module.exports = {
    event: Events.Warn,
    once: true,
    run: async (parameter) => {
        console.log(Event warn Triggered);
    },
};
  