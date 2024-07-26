
const { Events } = require("discord.js");

module.exports = {
    event: Events.GuildEmojiUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event guildEmojiUpdate Triggered");
    },
};
