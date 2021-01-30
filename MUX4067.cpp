//Arduino Library for CD74HC4067
//16 bit Analog Multiplexer

#include "Arduino.h"
#include <MUX4067.h>

MUX4067::MUX4067(uint8_t enable_pin, uint8_t s0_pin, uint8_t s1_pin,
					uint8_t s2_pin, uint8_t s3_pin)
{
	_enable_pin = enable_pin;
	_s0_pin = s0_pin;
	_s1_pin = s1_pin;
	_s2_pin = s2_pin;
	_s3_pin = s3_pin;
	
	pinMode(_s0_pin, OUTPUT);
	pinMode(_s1_pin, OUTPUT);
	pinMode(_s2_pin, OUTPUT);
	pinMode(_s3_pin, OUTPUT);
	pinMode(_enable_pin, OUTPUT);
	
	digitalWrite(_enable_pin, MUX4067_DISABLE);
	MUX4067_set_pin(0);
}

void MUX4067::MUX4067_enable()
{
	digitalWrite(_enable_pin, MUX4067_ENABLE);
}

void MUX4067::MUX4067_disable()
{
	digitalWrite(_enable_pin, MUX4067_DISABLE);
}

void MUX4067::MUX4067_set_pin(uint8_t pin)
{
	//check pins
	if(!(pin < MUX4067_PIN_COUNT)) return;
	
	//convert pin to binary and write to the mux	
	digitalWrite(_s0_pin, pin & 1);
	digitalWrite(_s1_pin, pin >> 1 & 1);
	digitalWrite(_s2_pin, pin >> 2 & 1);
	digitalWrite(_s3_pin, pin >> 3 & 1);
}
