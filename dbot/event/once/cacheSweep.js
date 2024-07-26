const { Events } = require("discord.js");
  
module.exports = {
    event: Events.CacheSweep,
    once: true,
    run: async (parameter) => {
        console.log(Event cacheSweep Triggered);
    },
};
  