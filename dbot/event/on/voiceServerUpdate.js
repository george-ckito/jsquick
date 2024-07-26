
const { Events } = require("discord.js");

module.exports = {
    event: Events.VoiceServerUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event voiceServerUpdate Triggered");
    },
};
