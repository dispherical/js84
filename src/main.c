#include <ti/screen.h>
#include <ti/getcsc.h>
#include <sys/power.h>
#include <stdlib.h>
#include <stdarg.h>
#include "elk.h"
#include <debug.h>
#include <string.h>
#include <sys/basicusb.h>

/* native elk stuff */
jsval_t dump(struct js *js, jsval_t *args, int nargs)
{
    js_dump(js);

    return js_mkundef();
}

/* screen.h */
jsval_t js_os_ClrHome(struct js *js, jsval_t *args, int nargs)
{
    os_ClrHome();
    return js_mkundef();
}

/* sys/power.h */
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

/* sys/basicusb.h */
jsval_t js_boot_USBBusPowered(struct js *js, jsval_t *args, int nargs)
{
    bool *powered = boot_USBBusPowered();
    return powered ? js_mktrue() : js_mkfalse();
}
jsval_t js_boot_USBSelfPowered(struct js *js, jsval_t *args, int nargs)
{
    bool *powered = boot_USBSelfPowered();
    return powered ? js_mktrue() : js_mkfalse();
}
jsval_t js_boot_USBResetChip(struct js *js, jsval_t *args, int nargs)
{
    boot_USBResetChip();
    return js_mkundef();
}
jsval_t js_boot_USBDisableTimers(struct js *js, jsval_t *args, int nargs)
{
    boot_USBDisableTimers();
    return js_mkundef();
}
jsval_t js_boot_USBEnableTimers(struct js *js, jsval_t *args, int nargs)
{
    boot_USBEnableTimers();
    return js_mkundef();
}
jsval_t js_boot_USBResetTimers(struct js *js, jsval_t *args, int nargs)
{
    boot_USBResetTimers();
    return js_mkundef();
}
jsval_t js_os_USBGetRequestStatus(struct js *js, jsval_t *args, int nargs)
{
    return js_mknum(os_USBGetRequestStatus());
}
int main(void)
{
    os_ClrHome();

    char mem[2000];
    struct js *js = js_create(mem, sizeof(mem));

    /* native elk stuff */
    js_set(js, js_glob(js), "dump", js_mkfun(dump));

    /* screen.h */
    js_set(js, js_glob(js), "ClrHome", js_mkfun(js_os_ClrHome));

    /* sys/power.h */
    js_set(js, js_glob(js), "boot_TurnOff", js_mkfun(js_boot_TurnOff));
    js_set(js, js_glob(js), "boot_TurnOn", js_mkfun(js_boot_TurnOn));
    js_set(js, js_glob(js), "boot_GetBatteryStatus", js_mkfun(js_boot_GetBatteryStatus));

    /* sys/basicusb.h */
    js_set(js, js_glob(js), "boot_USBBusPowered", js_mkfun(js_boot_USBBusPowered));
    js_set(js, js_glob(js), "boot_USBSelfPowered", js_mkfun(js_boot_USBSelfPowered));
    js_set(js, js_glob(js), "boot_USBResetChip", js_mkfun(js_boot_USBResetChip));
    js_set(js, js_glob(js), "boot_USBDisableTimers", js_mkfun(js_boot_USBDisableTimers));
    js_set(js, js_glob(js), "boot_USBEnableTimers", js_mkfun(js_boot_USBEnableTimers));
    js_set(js, js_glob(js), "boot_USBResetTimers", js_mkfun(js_boot_USBResetTimers));
    js_set(js, js_glob(js), "os_USBGetRequestStatus", js_mkfun(js_os_USBGetRequestStatus));

    jsval_t result = js_eval(js, "", ~0);
    printf("result: %s\n", js_str(js, result));
    while (!os_GetCSC())
        ;


    return 0;
}