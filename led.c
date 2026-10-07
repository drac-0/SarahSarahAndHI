#include <avr/io.h>
#include <util/delay.h>

int main(){
	//so ddrb is a bit sequence use to decide whether the pin would be an input or output?
	//yes
	//oh....

	DDRB = DDRB | (1 << DDB3);
	PORTB = PORTB | (1 << PORTB3);
	_delay_ms(5000);

	while(1){
		PORTB = PORTB & ~(1 << PORTB3);
		_delay_ms(1000);
	}

}
