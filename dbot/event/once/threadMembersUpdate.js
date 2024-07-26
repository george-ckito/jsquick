const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ThreadMembersUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event threadMembersUpdate Triggered);
    },
};
  