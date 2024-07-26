
const { Events } = require("discord.js");

module.exports = {
    event: Events.StageInstanceUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event stageInstanceUpdate Triggered");
    },
};
