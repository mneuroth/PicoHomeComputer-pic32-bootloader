/*
 * Copyright (C) 2014-2015 Darron Broad
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name `Darron Broad' nor the names of any contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*******************************************************************************
 *
 * R-PI 3V3 PIC32MX250F128B / PIC32MX270F256B
 *
 * LED blinky.
 *
 * This demo requires the chipKIT Pi boot loader.
 *
 *******************************************************************************
 *
 * Pinout
 * ------
 * !MCLR                                           1======28 AVDD 3V3
 * PGD3/VREF+/CVREF+/AN0/C3INC/RPA0/CTED1/PMD7/RA0 2      27 AVSS GND
 * PGC3/VREF-/CVREF-/AN1/RPA1/CTED2/PMD6/RA1       3      26 AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15
 * PGD1/AN2/C1IND/C2INB/C3IND/RPB0/RB0             4      25 CVREFOUT/AN10/C3INB/RPB14/BUSON/SCK1/CTED5/RB14
 * PGC1/AN3/C1INC/C2INA/RPB1/CTED12/PMD1/RB1       5      24 AN11/RPB13/CTPLS/PMRD/RB13
 * AN4/C1INB/C2IND/RPB2/SDA2/CTED13/PMD2/RB2       6      23 VUSB3V3
 * AN5/C1INA/C2INC/RTCC/RPB3/SCL2/PMWR/RB3         7      22 PGC2/RPB11/D-/RB11
 * VSS GND                                         8      21 PGD2/RPB10/D+/CTED1/RB10
 * OSC1/CLKI/RPA2/RA2                              9      20 VCAP
 * OSC2/CLKO/RPA3/PMA0/RA3                         10     19 VSS GND
 * SOSCI/RPB4/RB4                                  11     18 TDO/RPB9/SDA1/CTED4/PMD3/RB9
 * SOSCO/RPA4/T1CK/CTED9/PMA1/RA4                  12     17 TCK/RPB8/SCL1/CTED10/PMD4/RB8
 * VDD 3V3                                         13     16 TDI/RPB7/CTED3/PMD5/INT0/RB7
 * TMS/RPB5/USBID/RB5                              14=====15 VBUS
 *
 * chipKITPi
 * ---------
 * RA0	LED1
 * RB15	LED2
 *
 * Program
 * --------
 * pload program /dev/ttyAMA0 led.hex 24
 *
 ******************************************************************************/

#include "led.h"

void
delay_ms(uint32_t ms)
{
	uint32_t startTime, waitTime;

	startTime = ReadCoreTimer();
	waitTime = (FCY / 2000) * ms;

	while ((ReadCoreTimer() - startTime) < waitTime)
		;
}

static inline void
init_io(void)
{
#if defined(LED_MX795)
	/* ADC Digital Mode */
	AD1PCFG = 0xFFFF;

	/* Reset LED */
	LATE = 0x80;

	/* LED RE7 O/P */
	TRISE = 0x7F;
#else
	/* ADC Digital Mode */
	ANSELA = 0;
	ANSELB = 0;

	/* Set/Reset O/P */
	LATA = 0x0001;
	LATB = 0x0000;

	/* LED1 RA0 O/P */
	TRISAbits.TRISA0 = 0;

	/* LED2 RB15 O/P */
	TRISBbits.TRISB15 = 0;
#endif
}

int
main() 
{
	init_io();

	while(1) {
		/*  F = 1 Hz */
		delay_ms(500);
#if defined(LED_MX795)
		/* RA0 = ! RA0 */
		LATEbits.LATE7 = ~LATEbits.LATE7;
#else
		/* RA0 = ! RA0 */
		LATAbits.LATA0 = ~LATAbits.LATA0;

		/* RB15 = ! RB15 */
		LATBbits.LATB15 = ~LATBbits.LATB15;
#endif
	}
	return 0;
}
