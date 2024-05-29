/*
 * TIMER_A0_MSP432.h
 *
 *  Created on: Jun 8, 2021
 *      Author: Javier
 */

#ifndef DRIVERS_TIMER_A0_MSP432_H_
#define DRIVERS_TIMER_A0_MSP432_H_


#define TIMER_A_CTL_MC_0            ((uint16_t)0x0000)     /*!< Stop mode: Timer is halted */
#define TIMER_A_CTL_MC_1            ((uint16_t)0x0010)    /*!< Up mode: Timer counts up to TAxCCR0 */
#define TIMER_A_CTL_MC_2            ((uint16_t)0x0020) /*!< Continuous mode: Timer counts up to 0FFFFh */
#define TIMER_A_CTL_MC_3            ((uint16_t)0x0030)   /*!< Up/down mode: Timer counts up to TAxCCR0 then down to 0000h */


#define TIMER_A_CTL_TASSEL_0                     ((uint16_t)0x0000)              /*!< TAxCLK */
#define TIMER_A_CTL_TASSEL_1                     ((uint16_t)0x0100)              /*!< ACLK */
#define TIMER_A_CTL_TASSEL_2                    ((uint16_t)0x0200)              /*!< SMCLK */
#define TIMER_A_CTL_TASSEL_3                    ((uint16_t)0x0300)              /*!< INCLK */

#define TIMER_A_CTL_ID_0  ((uint16_t)0x0000)              /*!< /1 */
#define TIMER_A_CTL_ID_1   ((uint16_t)0x0040)              /*!< /2 */
#define TIMER_A_CTL_ID_2   ((uint16_t)0x0080)              /*!< /4 */
#define TIMER_A_CTL_ID_3    ((uint16_t)0x00C0)              /*!< /8 */



// Tama�o del timer.
#define TIMER16_16BitSize               ((uint16_t)0x0000)
//#define TIMER32_32BitSize           ((uint32_t)0x00000002)

//Limpiar bandera
#define TIMER_A0_CLR    ((uint16_t)0x0004)      /*!< TimerA clear */

// Encendido o apagado.
#define TIMER_A0_Enable             1
#define TIMER_A0_Disable            0

//Segundos y Microsegundos
#define MICROSEG 1000000
#define SEG      1

// Encendido del m�dulo timerA0.
extern void T16_Init(void);

// Habilita la interrupci�n del m�dulo timerA0.
extern void T16_EnableInterrupt(void);

// Deshabilita la interrupci�n del m�dulo timerA0.
extern void T16_DisableInterrupt(void);

// Configura el modo, divisor de tiempo y tama�o del m�dulo timerA0.
extern void T16_Configure(uint16_t Mode, uint16_t Prescale, uint16_t Clear);

// Brinda el valor al que debe cargarse el modulo del timerA0.
extern void T16_SetLoadValue(uint16_t LoadValue);


// Habilita el m�dulo timerA0.
extern void T16_EnableTimer(void);

// Deshabilita el m�dulo timerA0.
extern void T16_DisableTimer(void);

// Verifica el estado de interrupci�n del m�dulo timerA0.
extern void T16_ClearInterruptFlag(void);

//Funci�n que limpia la bandera
extern void T16_ClearInterrupFlag2(void);



#endif /* DRIVERS_TIMER_A0_MSP432_H_ */
