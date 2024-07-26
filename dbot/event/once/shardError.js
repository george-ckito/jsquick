const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ShardError,
    once: true,
    run: async (parameter) => {
        console.log(Event shardError Triggered);
    },
};
  