const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildEmojiDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event guildEmojiDelete Triggered);
    },
};
  