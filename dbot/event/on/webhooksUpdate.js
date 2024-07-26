
const { Events } = require("discord.js");

module.exports = {
    event: Events.WebhooksUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event webhooksUpdate Triggered");
    },
};
