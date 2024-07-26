
const { Events } = require("discord.js");

module.exports = {
    event: Events.StageInstanceCreate,
    once: false,
    run: async (parameter) => {
        console.log("Event stageInstanceCreate Triggered");
    },
};
