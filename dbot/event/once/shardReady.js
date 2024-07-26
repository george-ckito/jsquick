const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ShardReady,
    once: true,
    run: async (parameter) => {
        console.log(Event shardReady Triggered);
    },
};
  