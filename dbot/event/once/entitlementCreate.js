const { Events } = require("discord.js");
  
module.exports = {
    event: Events.EntitlementCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event entitlementCreate Triggered);
    },
};
  