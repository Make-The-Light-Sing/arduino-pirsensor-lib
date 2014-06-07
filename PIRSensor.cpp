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
 * Return if sensor has detected a movement in the past "timeout" duration
 *
 * This sensor is locked for a defined duration (at least 2.5 seconds) after
 * each time he has detected a movement, then he go down, still locked for 
 * the same duration, and then doesn't detect anything else as if there is 
 * no more movement.
 *
 * This function is used to have a constant HIGH output if movement doesn't
 * stop, after it stopped, output can stay HIGH for a maximum of 
 * "LockTime" + "Timeout"
 *
 * We recommand to have a timeout at least as long as the lock time.
 *
 * @return boolean
 */
boolean PIRSensor::hasMovement()
{
    if (triggered()) {
        return true;
    } else if (millis() - _triggered < _timeout) {
        return true;
    }
    return false;
}   // hasMovement

/**
 * Return if sensor has detected a movement
 * @return boolean
 */
boolean PIRSensor::triggered()
{
    if (digitalRead(_pin) == HIGH) {
        _triggered = millis();
        return true;
    }
    return false;
}   // triggered