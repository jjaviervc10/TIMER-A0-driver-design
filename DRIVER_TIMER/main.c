#include "msp.h"


/**
 * main.c
 */

void main(void){
    WDT_A->CTL = WDT_A_CTL_PW |  WDT_A_CTL_HOLD;

       P1->DIR |= BIT0;

     /* Función que contiene el valor a cargar para el TIMER_A0*/

       T16_SetLoadValue(65000);

       /*Función de inicalización del driver TIMER_AO*/

       T16_Init();

       while(1){

              if((T16_ClearInterruptFlag()) == 1)  {

                  P1->OUT ^= BIT0;

                   T16_ClearInterrupFlag2();
              }
          }

}
