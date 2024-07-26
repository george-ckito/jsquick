const { Events } = require("discord.js");
  
module.exports = {
    event: Events.VoiceServerUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event voiceServerUpdate Triggered);
    },
};
  