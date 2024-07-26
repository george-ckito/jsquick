const fs = require("fs");
const path = require("path");

async function readFiles(dir) {
  const directoryPath = path.join(process.cwd(), dir);
  return new Promise((resolve, reject) => {
    fs.readdir(directoryPath, (err, files) => {
      if (err) {
        return reject(err);
      }
      const fullPaths = files.map((file) => path.join(directoryPath, file));
      resolve(fullPaths);
    });
  });
}

module.exports = readFiles;
