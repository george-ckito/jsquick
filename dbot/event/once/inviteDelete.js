const { Events } = require("discord.js");
  
module.exports = {
    event: Events.InviteDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event inviteDelete Triggered);
    },
};
  