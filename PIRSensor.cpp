/*
 * PIRSensor.cpp
 *
 *  Created on: 07 june 2014
 *      Author: jeckel
 */

#include "PIRSensor.h"


/**
 * Main constructor
 */
PIRSensor::PIRSensor(byte pin, unsigned int timeout)
{
    _pin = pin;
    _timeout = timeout;
    pinMode(pin, INPUT);
}   // PIRSensor

/**
 * Main destructor
 */
PIRSensor::~PIRSensor()
{
}   // ~PIRSensor

/**
 * Return if sensor has detected a movement
 * @return boolean
 */
boolean PIRSensor::hasMovement()
{
    return (digitalRead(_pin) == HIGH);
}   // hasMovement