const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ThreadUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event threadUpdate Triggered);
    },
};
  