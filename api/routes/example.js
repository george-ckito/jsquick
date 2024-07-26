const { Router } = require("express");

const example = Router();

example.get("/", (req, res) => {
  res.send("Example Route, created using jsquick");
});

module.exports = {
  path: "/example",
  router: example,
};
