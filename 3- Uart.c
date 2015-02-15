#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

#use rs232(uart1, baud=9600) //9600 baudrate ile uart'i baslat

void main() {

while(TRUE) {
   printf("Hello world from FatihRobot'15\n");     //veri gonder
   delay_ms(500);                                  //bekle

   }
}