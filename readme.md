# js84

An attempt to get a JavaScript engine onto the Texas Instruments 84 Plus Color Edition Calculator. Uses [Elk](https://github.com/cesanta/elk) as the engine. [elk.c and elk.h have a seperate license](https://github.com/cesanta/elk/blob/master/LICENSE).

Functions are mapped 1-to-1 from C to JavaScript as best as possible.

## Things Needed
- node.js (if you wish to package files)
- the [CE Toolchain](https://ce-programming.github.io/toolchain/)
- sanity

## How to package a file
1. Install the toolchain
2. Make a JavaScript file. See src/main.c for the currently defined functions.
3. `node index.js /path/to/javascript/file.js` (e.g. `node index.js ./examples/dump.js`)
3. `make clean && make debug`
4. Tada! Load JS84.8xp onto your calculator.

## Supported functions
- [`dump();`](https://github.com/cesanta/elk#js_dump)
- [sys/basicusb.h](https://ce-programming.github.io/toolchain/headers/sys/basicusb.html)
- From [sys/power.h](https://ce-programming.github.io/toolchain/headers/sys/power.html): `boot_TurnOff`, `boot_TurnOn`, `boot_GetBatteryStatus`
- From [ti/screen.h](https://ce-programming.github.io/toolchain/headers/ti/screen.html): `os_ClrHome`