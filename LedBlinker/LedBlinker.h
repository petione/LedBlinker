#ifndef _BLINKER_H
#define _BLINKER_H

#if (ARDUINO >= 100)
# include <Arduino.h>
#else
# include <WProgram.h>
#endif

class LedBlinker {
	private:
        int _blinkPin;
        uint32_t _highDelay;
        uint32_t _lowDelay;
        uint32_t _lastBlink;
        uint32_t _lastBlinkR;
        int16_t _repeat;
        uint32_t _pause;
        uint32_t repeatCounter;
        boolean _blinkState;
        boolean _running;

	public:
		LedBlinker(int pin);
		void setDelay(uint32_t d);
		void setDelay(uint32_t h, uint32_t l);
                void setDelay(uint32_t h, uint32_t l,int16_t r);
                void setDelay(uint32_t h, uint32_t l, int16_t r,uint32_t p);
        void blink();
        void start();
        void stop();
};

#endif
