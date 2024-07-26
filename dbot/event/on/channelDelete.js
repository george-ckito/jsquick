
const { Events } = require("discord.js");

module.exports = {
    event: Events.ChannelDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event channelDelete Triggered");
    },
};
