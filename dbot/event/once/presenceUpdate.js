const { Events } = require("discord.js");
  
module.exports = {
    event: Events.PresenceUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event presenceUpdate Triggered);
    },
};
  