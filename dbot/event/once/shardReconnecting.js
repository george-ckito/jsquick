const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ShardReconnecting,
    once: true,
    run: async (parameter) => {
        console.log(Event shardReconnecting Triggered);
    },
};
  