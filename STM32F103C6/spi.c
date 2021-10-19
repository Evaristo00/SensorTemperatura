
#include "spi.h"

static uint32_t data [3] ;


 /* The function initializes the SPI module */
void spi1_init(){
RCC->APB2ENR |= 0xFC|(1<<12); /* enable clocks for GPIO and SPI1 */
GPIOA->CRL = 0xB4B34444; /* MOSI (PA7) and SCK(PA5): alt. func. out, MISO
(PA6): input, PA4 output */
SPI1->CR1 = 0x35D; /* SPE = 1, BR = 3, FFD = 0, SSI and SSM = 1 */
}


uint8_t spi1_transfer(uint8_t d){
SPI1->DR = d; /* send the contents of d */
while((SPI1->SR&(1<<0)) == 0); /* wait until RXNE is set */
return SPI1->DR; /* return the received data */
}


void imprimirTemp(){
   volatile uint32_t decena,unidad,coma;
   lcd_gotoXY(0,0);
   decena = data[0]/10;
   unidad = data[0] %10;
   lcd_sendData('0'+decena);
   lcd_sendData('0'+unidad);
   lcd_sendData('.');
   coma = data[1]>>5;
    lcd_sendData('0'+coma);
   }

 void activeSpi(){
    GPIOA->BSRR = (1<<4); 
    spi1_transfer(0x80);
    spi1_transfer(0x04);
    GPIOA->BRR = (1<<4); 
 }

 void leerTemp(){
       uint8_t c =0;
      GPIOA->BSRR = (1<<4); 
      spi1_transfer(0x02);
     for(c=0;c<3;c++){
	data[c]= spi1_transfer(0x00);
	}
	GPIOA->BRR = (1<<4);
 }
 