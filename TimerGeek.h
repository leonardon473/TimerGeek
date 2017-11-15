/*
 * TimerGeek.h
 *
 * TimerGeek - A timer library for Arduino.
 * Author: Leonardo Ramírez
 * Copyright (c) 2016
 *
 * This library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser
 * General Public License as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser
 * General Public License along with this library; if not,
 * write to the Robotics Club of CECYT 9, Org.,
 * 227 Mar Mediterráneo, Col. Popotla, Del. Miguel Hidalgo, C.P. 11400, MEX
 */

#ifndef TimerGeek_H
#define TimerGeek_H

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class TimerGeek
{
  private:
    boolean ledState;
    long interval;
    int led;
    unsigned long previousMillis;
    void (* fp)();
    boolean state;

  public:
    void blink(int Led, long Interval, boolean LedState);    
    void blinkFuntion();
    void blinkTimer();
    void funtion(long _interval, void (* _fp)(), boolean _state);
    void setInterval(long _interval);
    long getInterval();
    long howMuchLonger();
    long howMuchLongerOnce();
    void trigger();
    void Stop();
    void timerFuntion();
    void timerFuntionOnce();
} ;
#endif
