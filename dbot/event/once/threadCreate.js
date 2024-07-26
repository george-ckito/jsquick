const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ThreadCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event threadCreate Triggered);
    },
};
  