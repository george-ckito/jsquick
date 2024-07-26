const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ChannelCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event channelCreate Triggered);
    },
};
  