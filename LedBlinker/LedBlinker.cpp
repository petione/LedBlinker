#include <LedBlinker.h>

LedBlinker::LedBlinker(int pin) {
    _blinkPin = pin;
    _highDelay = 500;
    _lowDelay = 500;
    _lastBlink = 0;
    _repeat = 0;
    _pause=0;
    repeatCounter=0;
    _blinkState = false;
    _running = false;
    
}

void LedBlinker::setDelay(uint32_t d) {
    _highDelay = d;
    _lowDelay = d;
}

void LedBlinker::setDelay(uint32_t h, uint32_t l) {
    _highDelay = h;
    _lowDelay = l;
}
void LedBlinker::setDelay(uint32_t h, uint32_t l,uint32_t r) {
    _highDelay = h;
    _lowDelay = l;
    _repeat = r;
}

void LedBlinker::setDelay(uint32_t h, uint32_t l, uint32_t r, uint32_t p) {
   //h -stan wysoki, l - stan niski, r - liczba powtorzen, p - przerwa pomiedzy powtorzeniami
    _highDelay = h;
    _lowDelay = l;
    _repeat = r;
    _pause = p;
    
}

void LedBlinker::blink() {
    uint32_t diff = millis() - _lastBlink;
    uint32_t diffR = millis() - _lastBlinkR;
    uint32_t blinkDelay = _blinkState ? _highDelay : _lowDelay;
    
    if (diff >= blinkDelay) {
        _lastBlink = millis() - (diff - blinkDelay); // Account for any delay in calling blink
        _blinkState = !_blinkState;
        if (_running) {
            digitalWrite(_blinkPin, _blinkState ? HIGH : LOW);
           if(_blinkState==0)repeatCounter++;
            if((repeatCounter>=_repeat)&&_repeat!=0){
                repeatCounter=0;
                _running=false;
                // digitalWrite(_blinkPin, LOW);
             }
         }
    }

        if (((diffR > _pause+_repeat*(_highDelay+_lowDelay))&&_pause!=0)&&(_running==false)) {
        _lastBlinkR = millis() - (diffR - (_pause+_repeat*(_highDelay+_lowDelay))); // Account for any delay in calling blink
        _running=true;
        
    }
   


}

void LedBlinker::start() {
    pinMode(_blinkPin, OUTPUT);
    _running = true;
    _blinkState = false;
    _lastBlink = millis();
    _lastBlinkR = millis();
}

void LedBlinker::stop() {
    _running = false;
    digitalWrite(_blinkPin, LOW);
}
