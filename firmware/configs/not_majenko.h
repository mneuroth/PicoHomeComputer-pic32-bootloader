/* Not Majenko Boards */

//************************************************************************
#if defined(_BOARD_MAJENKO_SDXL_)
#define _CONFIG_VALID_
#if defined(PUT_CONFIG_BITS_HERE)

    /* Like SDXL but without PROG button */

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                        // Oscillator selection
    #pragma config POSCMOD  = EC                            // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_20                        // PLL multiplier
    #pragma config FPLLODIV = DIV_1                         // PLL output divider
    #pragma config FPBDIV   = DIV_1                         // Peripheral bus clock divider
    #pragma config FSOSCEN  = OFF                           // Secondary oscillator enable

    //* Clock control settings
    #pragma config IESO     = OFF                           // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                        // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                           // Clock output on OSCO pin enable

    //* USB Settings
    #pragma config UPLLEN   = ON                            // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                         // USB PLL input divider
    #pragma config FUSBIDIO = OFF                           // USB USID pin controlled by port function
    #pragma config FVBUSONIO = OFF                          // USB VBUSON pin controlled by port function

    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                           // Watchdog timer enable
    #pragma config WDTPS    = PS1024                        // Watchdog timer postscaler

    //* Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //* Debug settings
    #pragma config ICESEL   = ICS_PGx2                      // ICE pin selection
#endif

    #define CAPABILITIES (blCapBootLED | blCapUSBInterface | blCapAutoResetListening | CAPCOMMON)

    // LED sense
    #define LedOn       High

    // Boot LED
    #define BLedLat     E
    #define BLedBit     7

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          1000

    #define _CPU_NAME_                  "32MX795F512H"
    #define VEND                        vendMajenko
    #define PROD                        prodSDXL
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000             // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)        // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

/*
 * vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
 */
