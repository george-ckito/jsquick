const { table } = require("table");
const readFiles = require("./readFiles");
const { REST, Routes } = require("discord.js");

module.exports = async () => {
  const commands = [];
  const files = await readFiles("commands");
  const print = [["Command", "Loaded"]];
  files.forEach((filePath) => {
    const command = require(filePath);
    if ("data" in command && "execute" in command) {
      commands.push(command.data.toJSON());
      print.push([command.data.toJSON().name, "✅"]);
    } else {
      console.log(
        `[WARNING] The command at ${filePath} is missing a required "data" or "execute" property.`
      );
    }
  });
  // Construct and prepare an instance of the REST module
  const rest = new REST().setToken(process.env.TOKEN);

  // and deploy your commands!
  (async () => {
    try {
      console.log(
        `Started refreshing ${commands.length} application (/) commands.`
      );

      // The put method is used to fully refresh all commands in the guild with the current set
      const data = await rest.put(
        Routes.applicationGuildCommands(
          process.env.CLIENT,
          process.env.DEVGUILD
        ),
        { body: commands }
      );

      console.log(
        `Successfully reloaded ${data.length} application (/) commands.`
      );
      console.log(table(print));
    } catch (error) {
      // And of course, make sure you catch and log any errors!
      console.error(error);
    }
  })();
};
