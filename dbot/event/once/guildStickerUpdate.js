const { Events } = require("discord.js");
  
module.exports = {
    event: Events.GuildStickerUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event guildStickerUpdate Triggered);
    },
};
  