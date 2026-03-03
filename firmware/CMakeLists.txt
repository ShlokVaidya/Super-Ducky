cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(rp2350_dual_usb C CXX ASM)

set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(rp2350_dual_usb
    main.c
    usb_descriptors.c
    msc_disk.c
    emmc.c
)

target_link_libraries(rp2350_dual_usb
    pico_stdlib
    tinyusb_device
    tinyusb_board
)

pico_add_extra_outputs(rp2350_dual_usb)