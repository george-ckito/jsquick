const { Events } = require("discord.js");
  
module.exports = {
    event: Events.UserUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event userUpdate Triggered);
    },
};
  