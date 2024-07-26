
const { Events } = require("discord.js");

module.exports = {
    event: Events.ShardError,
    once: false,
    run: async (parameter) => {
        console.log("Event shardError Triggered");
    },
};
