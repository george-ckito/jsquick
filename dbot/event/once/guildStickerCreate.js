const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildStickerCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildStickerCreate Triggered);
    },
};
  