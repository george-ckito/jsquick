const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ChannelPinsUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event channelPinsUpdate Triggered);
    },
};
  