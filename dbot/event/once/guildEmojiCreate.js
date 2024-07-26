const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildEmojiCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildEmojiCreate Triggered);
    },
};
  