#include "emmc.h"

bool emmc_init(void)
{
    // TODO: Implement SD/MMC init sequence
    return true;
}

bool emmc_read(uint32_t lba, void* buffer, uint32_t size)
{
    // TODO: Send CMD17 / multi-block read
    return true;
}

bool emmc_write(uint32_t lba, void* buffer, uint32_t size)
{
    // TODO: Send CMD24 / multi-block write
    return true;
}

uint32_t emmc_get_block_count(void)
{
    return 32768; // example: 16MB
}