const loadFiles = require("./loadFiles");
const { table } = require("table");

async function handleRoutes(app) {
  try {
    const files = await loadFiles("routes");
    let prnt = [["Route", "Loaded"]];

    for (const file of files) {
      try {
        const { router, path } = require(file);
        prnt.push([path, "✅"]);
        app.use(path, router);
      } catch (err) {
        console.error(`Failed to load route from ${file}`);
        prnt.push([file, "❌"]);
      }
    }

    console.log(table(prnt));
  } catch (err) {
    console.error("Error loading routes:", err);
  }
}

module.exports = handleRoutes;
