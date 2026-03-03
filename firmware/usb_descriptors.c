#include "tusb.h"

extern bool hid_mode;

uint8_t const desc_hid_report[] =
{
    TUD_HID_REPORT_DESC_KEYBOARD()
};

uint8_t const desc_configuration_hid[] =
{
    TUD_CONFIG_DESCRIPTOR(1, 1, 0,
        TUD_CONFIG_DESC_LEN + TUD_HID_DESC_LEN,
        0, 100),

    TUD_HID_DESCRIPTOR(0, 0, HID_ITF_PROTOCOL_KEYBOARD,
        sizeof(desc_hid_report),
        0x81, 16, 10)
};

uint8_t const desc_configuration_msc[] =
{
    TUD_CONFIG_DESCRIPTOR(1, 1, 0,
        TUD_CONFIG_DESC_LEN + TUD_MSC_DESC_LEN,
        0, 100),

    TUD_MSC_DESCRIPTOR(0, 0, 0x81, 0x01, 64)
};

uint8_t const * tud_descriptor_configuration_cb(uint8_t index)
{
    return hid_mode ? desc_configuration_hid : desc_configuration_msc;
}