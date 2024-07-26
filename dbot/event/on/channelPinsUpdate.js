
const { Events } = require("discord.js");

module.exports = {
    event: Events.ChannelPinsUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event channelPinsUpdate Triggered");
    },
};
