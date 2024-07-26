const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ShardResume,
    once: true,
    run: async (parameter) => {
        console.log(Event shardResume Triggered);
    },
};
  