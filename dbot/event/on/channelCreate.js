
const { Events } = require("discord.js");

module.exports = {
    event: Events.ChannelCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event channelCreate Triggered");
    },
};
