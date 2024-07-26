
const { Events } = require("discord.js");

module.exports = {
    event: Events.StageInstanceDelete,
    once: false,
    run: async (parameter) => {
        console.log("Event stageInstanceDelete Triggered");
    },
};
