const { Events } = require("discord.js");
  
module.exports = {
    event: Events.WebhooksUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event webhooksUpdate Triggered);
    },
};
  