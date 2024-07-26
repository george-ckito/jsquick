const express = require("express");
const { default: mongoose } = require("mongoose");
const cors = require("cors");
const handleRoutes = require("./jsquick/handleRoutes");
const app = express();
require("dotenv").config();
const log = require("./jsquick/log");

app.use(express.json());
app.use(cors({}));

app.get("/", (req, res) => {
  res.send(
    '<h1>API Successfully Created!</h1> <p>API Created Using <a href="https://github.com/george-ckito/jsquick">jsquick</a> </p>'
  );
});

app.listen(process.env.PORT, async () => {
  log.logSuccess("API Started at http://localhost:" + process.env.PORT);
  try {
    await mongoose.connect(process.env.MONGODB + "/api");
    log.logSuccess("MongoDB connected");
  } catch (err) {
    log.logError("Couldn't connect to MongoDB");
  }
  try {
    await handleRoutes(app);
  } catch (err) {
    log.logError("Error handling routes:", err);
  }
});
