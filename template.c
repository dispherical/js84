#include <ti/screen.h>
#include <ti/getcsc.h>
#include <sys/power.h>
#include <stdlib.h>
#include <stdarg.h>
#include "elk.h"
#include <debug.h>
#include <string.h>

jsval_t dump(struct js *js, jsval_t *args, int nargs)
{
    js_dump(js);

    return js_mkundef();
}

/* sys/power.h */
jsval_t js_os_ClrHome(struct js *js, jsval_t *args, int nargs)
{
    os_ClrHome();
    return js_mkundef();
}
jsval_t js_boot_TurnOff(struct js *js, jsval_t *args, int nargs)
{
    boot_TurnOff();
    return js_mkundef();
}
jsval_t js_boot_TurnOn(struct js *js, jsval_t *args, int nargs)
{
    boot_TurnOn();
    return js_mkundef();
}
jsval_t js_boot_GetBatteryStatus(struct js *js, jsval_t *args, int nargs)
{
    uint8_t *battery = boot_GetBatteryStatus();
    return js_mknum((double)(*battery / 2));
}
int main(void)
{
    os_ClrHome();
    uint8_t var_type;
    char *var_name;
    void *vat_ptr = NULL;

    char mem[2000];
    struct js *js = js_create(mem, sizeof(mem));
    js_set(js, js_glob(js), "dump", js_mkfun(dump));

    /* screen.h */
    js_set(js, js_glob(js), "ClrHome", js_mkfun(js_os_ClrHome));
    js_set(js, js_glob(js), "boot_TurnOff", js_mkfun(js_boot_TurnOff));
    js_set(js, js_glob(js), "boot_TurnOn", js_mkfun(js_boot_TurnOn));
    js_set(js, js_glob(js), "boot_GetBatteryStatus", js_mkfun(js_boot_GetBatteryStatus));

    // evaluator
    while (!os_GetCSC())
        ;

    return 0;
}