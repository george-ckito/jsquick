const { default: mongoose } = require("mongoose");

module.exports = async (uri) => {
  await mongoose
    .connect(uri)
    .then(() => {
      console.log("Connected to MongoDB");
    })
    .catch((err) => console.error("Failed connecting to mongodb, " + err));
};
