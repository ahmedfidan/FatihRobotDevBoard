#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

void main() {
set_tris_e(0x00); //e portu output
while(TRUE) {
	output_high(PIN_E1);	//e1 high
	output_low(PIN_E2);		//e2 low
	delay_ms(500);			//bekle
	output_low(PIN_E1);		//e1 low
	output_high(PIN_E2);	//e2 high
	delay_ms(500);			
   }
}