require("dotenv").config();
const { Client, Events, GatewayIntentBits } = require("discord.js");
const eventHandler = require("./jsquick/handlers/eventHandler");
const deployCmds = require("./jsquick/deployCmds");
const cmdHandler = require("./jsquick/handlers/cmdHandler");

const client = new Client({ intents: Object.keys(GatewayIntentBits) });

(async () => {
  await cmdHandler(client);
  await deployCmds();
  await eventHandler(client);
})();
// client.once(Events.ClientReady, async (readyClient) => {
//   await eventHandler(client);
// });

client.login(process.env.TOKEN);
