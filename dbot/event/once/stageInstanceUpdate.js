const { Events } = require("discord.js");
  
module.exports = {
    event: Events.StageInstanceUpdate,
    once: true,
    run: async (parameter) => {
        console.log(Event stageInstanceUpdate Triggered);
    },
};
  