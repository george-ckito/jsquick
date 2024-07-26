const { Events } = require("discord.js");
  
module.exports = {
    event: Events.StageInstanceDelete,
    once: true,
    run: async (parameter) => {
        console.log(Event stageInstanceDelete Triggered);
    },
};
  