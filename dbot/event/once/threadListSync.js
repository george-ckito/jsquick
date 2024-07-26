const { Events } = require("discord.js");
  
module.exports = {
    event: Events.ThreadListSync,
    once: true,
    run: async (parameter) => {
        console.log(Event threadListSync Triggered);
    },
};
  