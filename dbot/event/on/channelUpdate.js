
const { Events } = require("discord.js");

module.exports = {
    event: Events.ChannelUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event channelUpdate Triggered");
    },
};
