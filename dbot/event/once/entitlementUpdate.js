const { Events } = require("discord.js");
  
module.exports = {
    event: Events.EntitlementUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event entitlementUpdate Triggered);
    },
};
  