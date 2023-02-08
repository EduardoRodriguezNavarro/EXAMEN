#ifndef UART_UART_H_
#define UART_UART_H_

extern void Configurar_UART1(void);
extern char readChar(void);
extern void printChar(char c);
extern void printString(char* string, int Largo);
extern int readString(char delimitador, char *string);
extern void NomInvert(char *Nombre, int Largo );


#endif /* UART_UART_H_ */