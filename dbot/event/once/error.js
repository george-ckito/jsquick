const { Events } = require("discord.js");
  
module.exports = {
    event: Events.Error,
    once: true,
    run: async (parameter) => {
        console.log(Event error Triggered);
    },
};
  