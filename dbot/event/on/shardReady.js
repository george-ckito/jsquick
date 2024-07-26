
const { Events } = require("discord.js");

module.exports = {
    event: Events.ShardReady,
    once: false,
    run: async (parameter) => {
        console.log("Event shardReady Triggered");
    },
};
