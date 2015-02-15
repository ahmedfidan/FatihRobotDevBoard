#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

void main() {
set_tris_e(0x01); //e0 input, digerleri output
while(TRUE) {
   //e0'da pull-up direnci var basili degilken 1
   //basildiginda 0  
   if(!input_state(PIN_E0)){   
   output_high(PIN_E1);      //buton basili ise led1'i yak 
   delay_ms(500);         //bekle
   }
   else                      //degilse
   output_low(PIN_E1);      //ledi sondur
   delay_ms(50);         
   }
}