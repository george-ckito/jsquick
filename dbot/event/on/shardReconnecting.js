
const { Events } = require("discord.js");

module.exports = {
    event: Events.ShardReconnecting,
    once: false,
    run: async (parameter) => {
        console.log("Event shardReconnecting Triggered");
    },
};
