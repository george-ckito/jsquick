const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ApplicationCommandPermissionsUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event applicationCommandPermissionsUpdate Triggered);
    },
};
  