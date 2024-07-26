const { table } = require("table");
const readFiles = require("../readFiles");

const eventHandler = async (client) => {
  let print = [["Event", "Loaded"]];
  const files = await readFiles("events");
  files.forEach((file) => {
    const event = require(file);
    print.push([event.event, "✅"]);
    if (event.once) {
      client.once(event.event, event.run);
    } else {
      client.on(event.event, event.run);
    }
  });
  return console.log(table(print));
};

module.exports = eventHandler;
