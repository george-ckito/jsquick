const { Events } = require("discord.js");
  
module.exports = {
    event: Events.StageInstanceCreate,
    once: true,
    run: async (parameter) => {
        console.log(Event stageInstanceCreate Triggered);
    },
};
  