const file = process.argv[2];
if (!file) throw new Error("File required");
const fs = require("node:fs");

if(!fs.existsSync(file)) throw new Error("File not found");


const program = JSON.stringify(fs.readFileSync(file, "utf8"))
const modified = fs.readFileSync("template.c", "utf8").replace("// evaluator", `jsval_t result = js_eval(js, ${program}, ~0);\nprintf("result: %s\\n", js_str(js, result));`);
fs.writeFileSync("src/main.c", modified)