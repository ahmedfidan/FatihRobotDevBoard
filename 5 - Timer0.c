#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)
#use rs232(uart1, baud=9600) //9600 baudrate ile uart'i baslat

void main() {
set_tris_d(0x00);   //led output
set_tris_b(0xFF);   //buton input

setup_timer_0(RTCC_DIV_256|RTCC_INTERNAL); //timer0 internal clock prescalar 256
int16 mydelay=0;

while(TRUE) {
if(!input(PIN_B1)){             //buton basiliysa
     set_timer0(0);             //timer0'i baslat
     while(!input(PIN_B1));     //buton basili kaldigi surece bekle
     mydelay=get_rtcc()*0.128;  //buton kalktiginda timer0 degerine gore kac ms hesapla
     printf("delay degeri %ld \n\r",mydelay);   //uart uzerinden degeri gonder
 }

//elde ettigimiz ms degerine gore ledi yakip sondur
output_high(PIN_D0);
delay_ms(mydelay);
output_low(PIN_D0);
delay_ms(mydelay);
}
}