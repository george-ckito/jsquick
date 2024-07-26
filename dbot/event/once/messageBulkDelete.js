const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessageBulkDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event messageBulkDelete Triggered);
    },
};
  