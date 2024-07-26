const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ChannelDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event channelDelete Triggered);
    },
};
  