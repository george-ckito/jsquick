
const { Events } = require("discord.js");

module.exports = {
    event: Events.UserUpdate,
    once: false,
    run: async (parameter) => {
        console.log("Event userUpdate Triggered");
    },
};
