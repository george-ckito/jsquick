
const { Events } = require("discord.js");

module.exports = {
    event: Events.ThreadMemberUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event threadMemberUpdate Triggered");
    },
};
