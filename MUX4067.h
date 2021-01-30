/*
 * Arduino Library for CD74HC4067 analog multiplexer
 * IC Datasheet: ti.com/lit/ds/symlink/cd74hc4067.pdf
 * Written By: Micah Black
 * Date: 2021-01-22
 * Revision History:
	 Micah Black - 2021-01-22 Original Writing
*/

#ifndef MUX4067_h
#define MUX4067_h


/***********DEVICE DEFINES**************
***************************************/

#define MUX4067_ENABLE		0
#define MUX4067_DISABLE		1

#define MUX4067_PIN_COUNT	16

/************CLASS*********************
**************************************/

class MUX4067
{
	public:
		MUX4067(uint8_t enable_pin, uint8_t s0_pin, uint8_t s1_pin,
					uint8_t s2_pin, uint8_t s3_pin); //constructor
		
		void MUX4067_enable();
		void MUX4067_disable();
		void MUX4067_set_pin(uint8_t pin); //pins 0 to 15
		
	private:
		//pins
		uint8_t _enable_pin;
		uint8_t _s0_pin;
		uint8_t _s1_pin;
		uint8_t _s2_pin;
		uint8_t _s3_pin;

};

#endif
