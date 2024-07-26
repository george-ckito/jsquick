
const { Events } = require("discord.js");

module.exports = {
    event: Events.ShardDisconnect,
    once: false,
    run: async (parameter) => {
        console.log("Event shardDisconnect Triggered");
    },
};
