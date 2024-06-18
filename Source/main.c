#include <stdio.h>
#include<stdint.h>
#include<stm32f411xe.h>
#include <uart.h>
#include <adc.h>
#include <string.h>
#define GPIOAEN			(1U<<0)
#define SR_EOC        (1U<<1)

char key;
uint32_t Sensor_value;
static void adc_callback(void);
void ADC_IRQHandler(void);

int main(void)
{
	RCC->AHB1ENR|=(1U<<0);
	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);
	uart2_txrx_init();
	pa1_adc_intrrupt_init();
	star_conversion();
	while(1)
	{
	}
}
static void adc_callback(void)
{
	//Sensor_value=adc_read();
	write_string(11,"Hello World");

}

void ADC_IRQHandler(void)
{

	/*Check for eoc in SR */
	if((ADC1->SR & SR_EOC)!=0)
	{
		/*Clear EOC */
		ADC1->SR&=~SR_EOC;
		/*Do something here*/
		adc_callback();

	}
}




