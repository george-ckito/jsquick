const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ShardDisconnect,
    once: true,
    run: async (parameter) => {
        console.log(Event shardDisconnect Triggered);
    },
};
  