const { Events } = require("discord.js");
  
module.exports = {
    event: Events.Debug,
    once: true,
    run: async (parameter) => {
        console.log(Event debug Triggered);
    },
};
  