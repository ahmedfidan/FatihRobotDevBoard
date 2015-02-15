#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)
#use rs232(uart1, baud=9600)

void main() {
setup_adc_ports(AN0);           //A0 portunu analog olarak ayarla
setup_adc(ADC_CLOCK_INTERNAL);  //internal clock kullan
set_adc_channel(0);             //okuma yapilacak kanali ayala
//1den fazla analog giris varsa her seferinde kanali degistirip okuma yapmak gerekir!
while(TRUE) {
   printf("Deger:%d",read_adc());   //adc degerini okuyup uart'dan gonder
   delay_ms(500);                   //bekle
   }
}
