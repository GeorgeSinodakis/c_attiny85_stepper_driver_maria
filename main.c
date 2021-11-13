#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define stepPin 1
#define dirPin 0
#define plusPin 3

void delayUs(uint16_t us)
{
	while (us)
	{
		_delay_us(1);
		us--;
	}
}

int main(void)
{

	DDRB = 1 << stepPin | 1 << dirPin | 1 << plusPin;
	PORTB = (1 << dirPin | 1 << plusPin);

	ADMUX = 1 << MUX1;
	ADCSRA = 1 << ADEN | 1 << ADSC | 1 << ADATE | 1 << ADPS2;
	ADCSRB = 0;

	while (1)
	{
		PORTB ^= 1 << stepPin;
		delayUs(400 + ADC);
	}
}
