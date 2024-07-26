
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildStickerDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event guildStickerDelete Triggered");
    },
};
