/*
 * adc.h
 *
 *  Created on: May 29, 2024
 *      Author: VOVAN
 */

#ifndef ADC_H_
#define ADC_H_
#include<stdint.h>
uint32_t adc_read(void);
void star_conversion(void);
void pa1_adc_intrrupt_init(void);

#endif /* ADC_H_ */
