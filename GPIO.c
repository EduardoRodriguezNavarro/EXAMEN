#include "lib/include.h"
/*extern void Configurar_GPIO(void)
{
    SYSCTL->RCGCGPIO |=(1<<5); 
    GPIOF->LOCK= 0x4C4F434B;   // 2) unlock GPIO Port F
    GPIOF->CR = 0x1F;           // allow changes to PF4-0
    GPIOF->AMSEL = 0x00;        // 3) disable analog on PF
    GPIOF->PCTL = 0x00000000;   // 4) PCTL GPIO on PF4-0
    GPIOF->DIR = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
    GPIOF->AFSEL = 0x00;        // 6) disable alt funct on PF7-0
    GPIOF->PUR = 0x11;          // enable pull-up on PF0 and PF4
    GPIOF->DEN = 0x1F;          // 7) enable digital I/O on PF4-0
}
*/
extern void Configurar_GPIO(void)
{
    SYSCTL->RCGCGPIO |=(1<<0)|(1<<1);  //pueto A

    //GPIOF->LOCK= 0x4C4F434B; // Es para desbloquear los puertos F, D y C que están bloqueado en la tiva ch 
   // GPIOF->CR = 0x1F;           // Para permitir cambios en los pines PF4-0 
    
    //Desabilita la función analogica del puerto, para funcionar como GPIO pag. 687
    GPIOA->AMSEL = 0x00; 
    GPIOB->AMSEL = 0x00;

    //Indicar que los pines a trabajan como GPIO son PA7-0
    GPIOA->PCTL = 0x00000000;   
    GPIOB->PCTL = 0x00000000; 
  
    //Para indicar que pines son entradas y cuales son salida 0 -> entrada, 1 -> salida 
    GPIOA->DIR = (0<<2); // PA2 ES entrada
    GPIOB->DIR = (1<<4); // PB4 ES salida

    //Se desabilita la función alternativa  PA7-0
    GPIOA->AFSEL = 0x00;   
    GPIOB->AFSEL = 0x00;  

    // Para habilitar que el edo. inicial de los pines sea pull-up O pull-down pag. 678
    GPIOA->PUR = (1<<2);// PA2  //Para boton de la tiva se pone 0x10 para pull up PF4

    //Se habilitan los pines como digitales PA2
    GPIOA->DEN = (1<<2);    
    GPIOB->DEN = (1<<4); 

    //pag. 667 Se limpian los pines a los que se asocian las interrupciones para poderlas configurar 
    GPIOA -> IM |= (0<<2);

    //pag. 664 Configurar que sea sensible al borde 
     GPIOA -> IS |= (0<<2);

    //pag. 665 registro para indicar que el IEV va a configurar que flancos detectar
    GPIOA -> IBE |= (0<<2);

    //pag. 666 Indicar con que flanco trabaja 
    GPIOA -> IEV |= (1<<2); //es con flanco de subida **L uso:  0 para  boton de la tiva  F4

    //pag. 668 establecer que no ha ocurrido ninguna interrupción en esos pines (edo inicial)
    GPIOA -> RIS |= (0<<2);

    //PAG. 667 La interrupción del pin es enviada al controlador de interrup.
    GPIOA -> IM |= (1<<2);
 
    //pag. 104 Configurar la interrupción correspondiente al puerto A -> int 0
    // bloque de int. 3       2      1    0      
    //              [4n+3] [4n+2] [4n+1] [4n] ---> [4n] = 0(valor de la int) : n=0
    //                FF    FF      FF    00    (los 00 indica lo que se le suma)
    NVIC -> IP[0] = (NVIC ->IP[0]&0xFFFFFF00) | 0x00000020; //0 es el numero de prioridad (n), el 2 se pone en la posición que cae la int. según pag. 153

    // Habilitar interrupción pag. 142 
    NVIC -> ISER[0] = (1<<0); //0x00000001; //se pone 1 en la interrupción 0 y es ISER[0] porque no se ocupa el 2do nivel, la int. está dentro de las 31 int del 1er nivel 
    //GPIOA->DATA = (1<<3);
}

extern void Delay(void)
{
  unsigned long volatile time;
  time = 1600000;
  while(time)
  {
		time--;
  }
}
