
const { Events } = require("discord.js");

module.exports = {
    event: Events.MessagePollVoteRemove,
    once: false,
    run: async (parameter) => {
        console.log("Event messagePollVoteRemove Triggered");
    },
};
