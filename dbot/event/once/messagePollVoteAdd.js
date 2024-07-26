const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessagePollVoteAdd,
    once: true,
    run: async (parameter) => {
        console.log(Event messagePollVoteAdd Triggered);
    },
};
  