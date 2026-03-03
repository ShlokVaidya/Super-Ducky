#ifndef EMMC_H
#define EMMC_H

bool emmc_init(void);
bool emmc_read(uint32_t lba, void* buffer, uint32_t size);
bool emmc_write(uint32_t lba, void* buffer, uint32_t size);
uint32_t emmc_get_block_count(void);

#endif