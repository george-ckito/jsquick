
const { Events } = require("discord.js");

module.exports = {
    event: Events.ThreadMembersUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event threadMembersUpdate Triggered");
    },
};
