const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildEmojiUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildEmojiUpdate Triggered);
    },
};
  