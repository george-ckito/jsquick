const { Events } = require("discord.js");
  
module.exports = {
    event: Events.InviteCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event inviteCreate Triggered);
    },
};
  