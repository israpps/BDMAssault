#include <bdm.h>
#include <irx.h>
#include <loadcore.h>
#include <stdio.h>

// #define DEBUG  //comment out this line when not debugging
#include "include/module_debug.h"

#define MAJOR_VER 2
#define MINOR_VER 1

IRX_ID("bdm", MAJOR_VER, MINOR_VER);

extern struct irx_export_table _exp_bdm;
extern int bdm_init();
extern void part_init();
extern int bdmfs_fatfs_start(int argc, char *argv[]);

int _start(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    printf("Block Device Manager (BDM) v%d.%d\n", MAJOR_VER, MINOR_VER);

    if (RegisterLibraryEntries(&_exp_bdm) != 0) {
        M_PRINTF("ERROR: Already registered!\n");
        return MODULE_NO_RESIDENT_END;
    }

    // initialize the block device manager
    if (bdm_init() < 0) {
        M_PRINTF("ERROR: BDM init failed!\n");
        return MODULE_NO_RESIDENT_END;
    }

    // initialize the partition driver
    part_init();

    return bdmfs_fatfs_start(argc, argv); //we return this func because both modules must be ready to work
}
