
const { Events } = require("discord.js");

module.exports = {
    event: Events.ApplicationCommandPermissionsUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event applicationCommandPermissionsUpdate Triggered");
    },
};
