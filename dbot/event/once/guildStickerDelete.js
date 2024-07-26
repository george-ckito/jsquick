const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildStickerDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event guildStickerDelete Triggered);
    },
};
  