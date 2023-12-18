#define MAJOR_VER 1
#define MINOR_VER 1

#include "include/scsi.h"
#include <irx.h>
#include <loadcore.h>
#include <stdio.h>

// #define DEBUG  //comment out this line when not debugging
#include "include/module_debug.h"

//IRX_ID(MODNAME, MAJOR_VER, MINOR_VER);

extern int usb_mass_init(void);

int usbmass_bd_start(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    M_PRINTF("USBD ASSAULT: starting USBMASS Side\n");

    // initialize the SCSI driver
    if (scsi_init() != 0) {
        M_PRINTF("ERROR: initializing SCSI driver!\n");
        return MODULE_NO_RESIDENT_END;
    }

    // initialize the USB driver
    if (usb_mass_init() != 0) {
        M_PRINTF("ERROR: initializing USB driver!\n");
        return MODULE_NO_RESIDENT_END;
    }

    // return resident
    return MODULE_RESIDENT_END;
}
