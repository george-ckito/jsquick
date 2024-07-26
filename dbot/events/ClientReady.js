const { Events } = require("discord.js");
const connectMongo = require("../jsquick/connectMongo");

module.exports = {
  event: Events.ClientReady,
  once: true,
  run: async (client) => {
    console.log(`Ready! Logged in as ${client.user.tag}`);
    await connectMongo(process.env.MONGODB);
  },
};
