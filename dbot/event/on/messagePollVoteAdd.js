
const { Events } = require("discord.js");

module.exports = {
    event: Events.MessagePollVoteAdd,
    once: false,
    run: async (parameter) => {
        console.log("Event messagePollVoteAdd Triggered");
    },
};
