const { Events } = require("discord.js");
  
module.exports = {
    event: Events.EntitlementDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event entitlementDelete Triggered);
    },
};
  