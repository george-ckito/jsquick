const { Events } = require("discord.js");
  
module.exports = {
    event: Events.VoiceStateUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event voiceStateUpdate Triggered);
    },
};
  