/*
 * TIMER_A0_MSP432.c
 *
 *  Created on: Jun 8, 2021
 *      Author: Javier
 */

#include "msp.h"
#include "TIMER_A0_MSP432.h"
/*FUNCTION******************************************************************************
 *
 * Function Name    : T16_Init
 * Returned Value   : None.
 * Comments         :
 *    Función usada para habilitar el modulo de timerA0 en la macro de BITBAND_PERI
 *    así también se configura la esacala a la que va a trabajar nuetra funcion de tiempo,
 *    el modo a emplear para la ejecución de este y el tamaño en bits del timerA0
 *END***********************************************************************************/
void T16_Init(void)
{
    T16_Configure( TIMER_A_CTL_TASSEL_2  ,TIMER_A_CTL_ID_0, TIMER_A_CTL_MC_1 );
}

/*FUNCTION******************************************************************************
 *
 * Function Name    : void T16_EnableInterrupt
 * Returned Value   : None.
 * Comments         :
 *    Función usada para habilitar la interupción para el uso de timer del módulo TIMERA0
 *    en la macro de BITBAND_PERI
 *
 *END***********************************************************************************/

void T16_EnableInterrupt(void)
{
    BITBAND_PERI( TIMER_A0->CTL, TIMER_A_CTL_IE_OFS  ) = 1;
}

/*FUNCTION******************************************************************************
 *
 * Function Name    : void  T16_DisableInterrupt
 * Returned Value   : None.
 * Comments         :
 *    Función usada para dehabilitar el registro  para el uso de timer en la macro de BITBAND_PERI
 *    asignandolo el valor de 0 a la resepectiva macro
 *END***********************************************************************************/
// Deshabilita la interrupción del módulo timerA0.
void T16_DisableInterrupt(void)
{
    BITBAND_PERI( TIMER_A0->CTL, TIMER_A_CTL_IE_OFS ) = 0;
}
/*FUNCTION******************************************************************************
 *
 * Function Name    : void T16_Configure
 * Returned Value   : None.
 * Comments         :
 *    Función usada para habilitar el registro  para el uso de timer en la macro  y diseñarlo
 *    configurando el modo. divisor de tiempo y el tamaño del módulo timerA0
 *END***********************************************************************************/
void T16_Configure(uint16_t TASSEL, uint16_t Prescale, uint16_t Mode)
{
    TIMER_A0->CTL |= (TASSEL | Prescale | Mode);
}
/*FUNCTION******************************************************************************
 *
 * Function Name    : void T16_SetLoadValue
 * Returned Value   : None.
 * Comments         :
 *    Función usada para brindatr el valor al que debe cargarse el modulo timerA0
 *END***********************************************************************************/

void T16_SetLoadValue(uint16_t LoadValue)
{

    TIMER_A0->CCR[0] = LoadValue;
}

/*FUNCTION******************************************************************************
 *
 * Function Name    : void T16_EnableTimer
 * Returned Value   : None.
 * Comments         :
 *    Función usada para habilitar el modulo del timerA0 cargandole un valor de 1 a la macro
 *END***********************************************************************************/
void T16_EnableTimer(void)
{
    BITBAND_PERI (TIMER_A0->CTL, TIMER_A_CTL_IE_OFS   ) = 1;
}

/*FUNCTION******************************************************************************
 *
 * Function Name    : void T16_DisableTimer
 * Returned Value   : None.
 * Comments         :
 *    Función usada para habilitar el registro  para el uso de timer en la macro de BITBAND_PERI
 *    así también se configura la esacala a la que va a trabajar nuetra funcion de tiempo, la cual esta en milisegundos
 *END***********************************************************************************/
void T16_DisableTimer(void)
{
    BITBAND_PERI (TIMER_A0->CTL, TIMER_A_CTL_IE_OFS   ) = 0;
}
/*FUNCTION******************************************************************************
 *
 * Function Name    : void T16_ClearInterruptFlag
 * Returned Value   : None.
 * Comments         :
 *    Función usada pata limpiar la bandera de interrupción del módulo timerA0
 *END***********************************************************************************/

void T16_ClearInterruptFlag(void)
{
    static int t ;
    if ((TIMER_A0->CTL & TIMER_A_CTL_IFG)!=0){

        t = 1;
    }
    else{
        t = 0;
    }
}

/*FUNCTION******************************************************************************
 *
 * Function Name    : void T16_ClearInterrupClear
 * Returned Value   : None.
 * Comments         :
 *    Función usada pata limpiar la bandera de interrupción del módulo timerA0
 *END***********************************************************************************/
// Limpia la bandera de interrupción del módulo timerA0.
void T16_ClearInterrupFlag2(void)
{
   (TIMER_A0->CTL &= ~ TIMER_A_CTL_IFG);
}


