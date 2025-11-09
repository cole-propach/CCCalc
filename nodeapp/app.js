const express = require("express");
const app = express();
const fs = require('fs');

require("./routes.js")(app);

const port = 3000;
app.listen(port, () => console.log("Listening on port " + port));