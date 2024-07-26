const { Collection } = require("discord.js");
const readFiles = require("../readFiles");

module.exports = async (client) => {
  client.commands = new Collection();
  const files = await readFiles("commands");
  files.forEach((file) => {
    const cmd = require(file);
    if ("data" in cmd && "execute" in cmd) {
      client.commands.set(cmd.data.name, cmd);
    } else {
      console.log(
        `[WARNING] The command at ${file} is missing a required "data" or "execute" property.`
      );
    }
  });
};
