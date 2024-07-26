const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ThreadMemberUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event threadMemberUpdate Triggered);
    },
};
  