const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ChannelUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event channelUpdate Triggered);
    },
};
  