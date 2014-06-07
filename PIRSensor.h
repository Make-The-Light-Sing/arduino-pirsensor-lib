/*
 * PIRSensor.h
 *
 *  Created on: 20 mars 2014
 *      Author: jeckel
 */

#ifndef PIRSENSOR_H_
#define PIRSENSOR_H_

#include <stddef.h>
#if defined(ARDUINO) && ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

class PIRSensor
{
public:
    PIRSensor(byte pin, unsigned int timeout = 3000);
    boolean hasMovement();
    boolean triggered();
    virtual ~PIRSensor();
private:
    byte _pin;
    unsigned int _timeout;
    unsigned long _triggered;
};

#endif /* PIRSENSOR_H_ */
