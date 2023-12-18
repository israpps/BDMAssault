#include <bdm.h>
#include <intrman.h>
#include <irx.h>
#include <loadcore.h>
#include <stdio.h>
#include <sysmem.h>
#include <cdvdman.h>

#include "include/ff.h"
#include "include/fs_driver.h"

//#define DEBUG  //comment out this line when not debugging
#include "include/module_debug.h"

#define MAJOR_VER 1
#define MINOR_VER 4

// IRX_ID("bdmff", MAJOR_VER, MINOR_VER); //because were fusing two IRX

static struct file_system g_fs = {
    .priv = NULL,
    .name = "fatfs",
    .connect_bd = connect_bd,
    .disconnect_bd = disconnect_bd,
};

int bdmfs_fatfs_start(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    printf("BDM_ASSAULT: starting Fatfs side\n");

    // initialize the file system driver
    if (InitFS() != 0) {
        M_DEBUG("Error initializing FatFs driver!\n");
        return MODULE_NO_RESIDENT_END;
    }

    // Connect to block device manager
    bdm_connect_fs(&g_fs);

    // return resident
    return MODULE_RESIDENT_END;
}

void *malloc(int size)
{
    void *result;
    int OldState;

    CpuSuspendIntr(&OldState);
    result = AllocSysMemory(ALLOC_FIRST, size, NULL);
    CpuResumeIntr(OldState);

    return result;
}

void free(void *ptr)
{
    int OldState;

    CpuSuspendIntr(&OldState);
    FreeSysMemory(ptr);
    CpuResumeIntr(OldState);
}
