#include "pico/stdlib.h"
#include "bsp/board.h"
#include "tusb.h"

#define BOOT_MODE_PIN 22

bool hid_mode = false;

int main(void)
{
    board_init();

    gpio_init(BOOT_MODE_PIN);
    gpio_set_dir(BOOT_MODE_PIN, GPIO_IN);
    gpio_pull_up(BOOT_MODE_PIN);

    sleep_ms(10);

    hid_mode = (gpio_get(BOOT_MODE_PIN) == 0);

    tusb_init();

    while (1)
    {
        tud_task();
    }
}