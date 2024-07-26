const { blue, yellow, red, blueBright, green } = require("console-log-colors");
const { name, version } = require("../package.json");

class log {
  logTitle() {
    console.log(blueBright(`${name}  ${version}`));
  }
  logWarning(str) {
    console.log(`${yellow("WARN")} ${str}`);
  }
  logError(str) {
    console.log(`${red("ERRO")} ${str}`);
  }
  logInfo(str) {
    console.log(`${blue("INFO")} ${str}`);
  }
  logSuccess(str) {
    console.log(`${green("SUCC")} ${str}`);
  }
}
module.exports = new log();
