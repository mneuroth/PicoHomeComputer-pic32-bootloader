/* Not Element 14 Boards */

//************************************************************************
#if defined(_BOARD_CHIPKIT_PI_48_)
#define _CONFIG_VALID_
#if defined(PUT_CONFIG_BITS_HERE)

    /* Like chipKIT Pi but with 48MHz oscillator */

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                        // Oscillator selection
    #pragma config POSCMOD  = HS                            // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_24                        // PLL multiplier
    #pragma config FPLLODIV = DIV_2                         // PLL output divider
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
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                           // JTAG port disabled

    //* Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      // ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           // Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           // Allow multiple reconfigurations
#endif

    // LED1 on RA0
    // LED2 on RB15
    // Boot button on RB9
    #define CAPABILITIES (blCapBootLED | blCapUARTInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     A
    #define BLedBit     0

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    9

    // Program button
    #define PBntPort    B
    #define PBntBit     9

    // Other capabilities
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U2RXR = 0x2)       // RB1 -> U2RX
    #define UARTMapTX()                 (RPB0R = 0x2)       // RB0 -> U2TX

    #define _CPU_NAME_                  "32MX250F128B"
    #define VEND                        vendElement14
    #define PROD                        prodChipkitPi
    #define F_CPU                       48000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                // In bytes

//************************************************************************
#elif defined(_BOARD_CHIPKIT_PI_USB_48_)
#define _CONFIG_VALID_
#if defined(PUT_CONFIG_BITS_HERE)

    /* Like chipKIT Pi USB but with 48MHz oscillator */

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                        // Oscillator selection
    #pragma config POSCMOD  = HS                            // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_24                        // PLL multiplier
    #pragma config FPLLODIV = DIV_2                         // PLL output divider
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
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                           // JTAG port disabled

    //* Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      // ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           // Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           // Allow multiple reconfigurations
#endif

    // LED1 on RA0
    // LED2 on RB15
    // Boot button on RB9
    #define CAPABILITIES (blCapBootLED | blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     A
    #define BLedBit     0

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    9

    // Program button
    #define PBntPort    B
    #define PBntBit     9

    #define _CPU_NAME_                  "32MX250F128B"
    #define VEND                        vendElement14
    #define PROD                        prodChipkitPi
    #define F_CPU                       48000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                // In bytes

//************************************************************************
#elif defined(_BOARD_CHIPKIT_PI_MX270_)
#define _CONFIG_VALID_
#if defined(PUT_CONFIG_BITS_HERE)

    /* Like chipKIT Pi but with MX270 processor */

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                        // Oscillator selection
    #pragma config POSCMOD  = HS                            // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_20                        // PLL multiplier
    #pragma config FPLLODIV = DIV_2                         // PLL output divider
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
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                           // JTAG port disabled

    //* Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      // ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           // Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           // Allow multiple reconfigurations
#endif

    // LED1 on RA0
    // LED2 on RB15
    // Boot button on RB9
    #define CAPABILITIES (blCapBootLED | blCapUARTInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     A
    #define BLedBit     0

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    9

    // Program button
    #define PBntPort    B
    #define PBntBit     9

    // Other capabilities
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U2RXR = 0x2)       // RB1 -> U2RX
    #define UARTMapTX()                 (RPB0R = 0x2)       // RB0 -> U2TX

    #define _CPU_NAME_                  "32MX270F256B"
    #define VEND                        vendElement14
    #define PROD                        prodChipkitPi
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x40000-0x1000)    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                // In bytes

//************************************************************************
#elif defined(_BOARD_CHIPKIT_PI_MX270_48_)
#define _CONFIG_VALID_
#if defined(PUT_CONFIG_BITS_HERE)

    /* Like chipKIT Pi but with MX270 processor and 48MHz oscillator */

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                        // Oscillator selection
    #pragma config POSCMOD  = HS                            // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_24                        // PLL multiplier
    #pragma config FPLLODIV = DIV_2                         // PLL output divider
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
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                           // JTAG port disabled

    //* Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      // ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           // Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           // Allow multiple reconfigurations
#endif

    // LED1 on RA0
    // LED2 on RB15
    // Boot button on RB9
    #define CAPABILITIES (blCapBootLED | blCapUARTInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     A
    #define BLedBit     0

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    9

    // Program button
    #define PBntPort    B
    #define PBntBit     9

    // Other capabilities
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U2RXR = 0x2)       // RB1 -> U2RX
    #define UARTMapTX()                 (RPB0R = 0x2)       // RB0 -> U2TX

    #define _CPU_NAME_                  "32MX270F256B"
    #define VEND                        vendElement14
    #define PROD                        prodChipkitPi
    #define F_CPU                       48000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x40000-0x1000)    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                // In bytes

//************************************************************************
#elif defined(_BOARD_CHIPKIT_PI_MX270_USB_48_)
#define _CONFIG_VALID_
#if defined(PUT_CONFIG_BITS_HERE)

    /* Like chipKIT Pi USB but with MX270 processor and 48MHz oscillator */

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                        // Oscillator selection
    #pragma config POSCMOD  = HS                            // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_24                        // PLL multiplier
    #pragma config FPLLODIV = DIV_2                         // PLL output divider
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
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                           // JTAG port disabled

    //* Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      // ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           // Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           // Allow multiple reconfigurations
#endif

    // LED1 on RA0
    // LED2 on RB15
    // Boot button on RB9
    #define CAPABILITIES (blCapBootLED | blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     A
    #define BLedBit     0

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    9

    // Program button
    #define PBntPort    B
    #define PBntBit     9

    #define _CPU_NAME_                  "32MX270F256B"
    #define VEND                        vendElement14
    #define PROD                        prodChipkitPi
    #define F_CPU                       48000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x40000-0x1000)    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                // In bytes

//************************************************************************
#elif defined(_BOARD_BREADBOARD_)   // UART (Default) version
#define _CONFIG_VALID_
#if defined(PUT_CONFIG_BITS_HERE)

    /* Like chipKIT Pi but with 40MHz internal oscillator */

    //* Oscillator Settings
    #pragma config FNOSC    = FRCPLL                        // Oscillator selection
    #pragma config POSCMOD  = OFF                           // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_20                        // PLL multiplier
    #pragma config FPLLODIV = DIV_2                         // PLL output divider
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
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                           // JTAG port disabled

    //* Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      // ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           // Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           // Allow multiple reconfigurations
#endif

    // LED1 on RA0
    #define CAPABILITIES (blCapBootLED | blCapUARTInterface | blCapAutoResetListening | CAPCOMMON)

    // LED sense
    #define LedOn       High

    // Boot LED
    #define BLedLat     A
    #define BLedBit     0

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          5000                // no less than 5 seconds
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U2RXR = 0x2)       // RB1 -> U2RX
    #define UARTMapTX()                 (RPB0R = 0x2)       // RB0 -> U2TX

    #define _CPU_NAME_                  "32MX250F128B"
    #define VEND                        vendElement14
    #define PROD                        prodChipkitPi
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                // In bytes

//************************************************************************
#elif defined(_BOARD_BREADBOARD_9600_)   // UART (Default) version
#define _CONFIG_VALID_
#if defined(PUT_CONFIG_BITS_HERE)

    /* Like chipKIT Pi but with 40MHz internal oscillator and 9600 baud upload */

    //* Oscillator Settings
    #pragma config FNOSC    = FRCPLL                        // Oscillator selection
    #pragma config POSCMOD  = OFF                           // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_20                        // PLL multiplier
    #pragma config FPLLODIV = DIV_2                         // PLL output divider
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
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                           // JTAG port disabled

    //* Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      // ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           // Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           // Allow multiple reconfigurations
#endif

    // LED1 on RA0
    #define CAPABILITIES (blCapBootLED | blCapUARTInterface | blCapAutoResetListening | CAPCOMMON)

    // LED sense
    #define LedOn       High

    // Boot LED
    #define BLedLat     A
    #define BLedBit     0

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          5000                // no less than 5 seconds
    #define BOOTLOADER_UART             2
    #define BAUDRATE                    9600
    #define UARTMapRX()                 (U2RXR = 0x2)       // RB1 -> U2RX
    #define UARTMapTX()                 (RPB0R = 0x2)       // RB0 -> U2TX

    #define _CPU_NAME_                  "32MX250F128B"
    #define VEND                        vendElement14
    #define PROD                        prodChipkitPi
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                // In bytes

//************************************************************************
#endif

/*
 * vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
 */
