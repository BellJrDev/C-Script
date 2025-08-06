// JS file to generate string.impl.h based on the current environment

const path = require("path");
const outputPath = path.join(__dirname, "../C-Script/include/string.impl.h");

const fs = require("fs");
fs.copyFileSync(
  "include/detail/String.impl.def",
  "include/detail/String.impl.h"
);
console.log(`[node] ✅ string.impl.h generated at ${outputPath}`);
