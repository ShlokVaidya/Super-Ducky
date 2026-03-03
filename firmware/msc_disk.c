#include "tusb.h"
#include "emmc.h"

int32_t tud_msc_read10_cb(uint8_t lun,
                          uint32_t lba,
                          uint32_t offset,
                          void* buffer,
                          uint32_t bufsize)
{
    emmc_read(lba, buffer, bufsize);
    return bufsize;
}

int32_t tud_msc_write10_cb(uint8_t lun,
                           uint32_t lba,
                           uint32_t offset,
                           uint8_t* buffer,
                           uint32_t bufsize)
{
    emmc_write(lba, buffer, bufsize);
    return bufsize;
}

uint32_t tud_msc_get_block_count_cb(uint8_t lun)
{
    return emmc_get_block_count();
}