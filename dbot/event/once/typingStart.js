const { Events } = require("discord.js");
  
module.exports = {
    event: Events.TypingStart,
    once: true,
    run: async (parameter) => {
        console.log(Event typingStart Triggered);
    },
};
  