const { Events } = require("discord.js");
  
module.exports = {
    event: Events.MessagePollVoteRemove,
    once: true,
    run: async (parameter) => {
        console.log(Event messagePollVoteRemove Triggered);
    },
};
  