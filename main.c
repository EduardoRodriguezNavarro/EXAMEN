//EXAMEN FINAL EDUARDO
#include "lib/include.h"
//PAGINA1351 PA CONECTAR EL MODULO


extern void GPIOA_INT_ISR(void) 
{
    if (GPIOA->RIS == (1<<2))
    {
    GPIOB->DATA = (1<<4);
    }
    GPIOA->ICR |= (1<<2);  
}

int main(void)
{
    //___________________________________________VARIABLES
    //uint16_t valor = 0;
    /*char c='5';
    int Largo=100;//VARIABLE DONDE ALMACENARÉ EL LARGO DE MI ARREGLO
    char Nombre[Largo]; //ARREGLO DONDE ALMACENARÉ EL NOMBRE
    */
    uint16_t Result[3];
    uint16_t duty[3];


    Configurar_PLL(_25MHZ);  //Confiuracion de velocidad de reloj de la tiva 
    Configurar_UART1();//Yo FCLK 25MHZ Baudrate 57600


    //Experimento 1
    //  Configurar_UART1(); //Saul,Fabela -fclk 25MHZ Baud-rate 57600
    
    
    
     Configurar_GPIO();
    // Configura_Reg_ADC0();
   // Homogeneidad();
    //printString("Holis Bolis");
    //printChar(c);
    //printChar(b);
    //printString("HOLA\n");
   // char *arr = readString(',');
   // printString(&arr[0]);
   GPIOA->DATA = (1<<3);
    while(1)
    {
         

        //Se llama a la función para leer y convertir valores del ADC
        //ADC0_InSeq2(Result,duty);

    }

}