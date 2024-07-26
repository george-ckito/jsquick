
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildEmojiDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event guildEmojiDelete Triggered");
    },
};
