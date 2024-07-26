
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildStickerCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildStickerCreate Triggered");
    },
};
