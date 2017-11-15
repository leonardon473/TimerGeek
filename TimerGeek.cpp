/*
 * TimerGeek.cpp
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

 #include "TimerGeek.h"
 #if defined(ARDUINO) && ARDUINO >= 100
 #include <Arduino.h>
 #else
 #include <WProgram.h>
 #endif

 static inline unsigned long elapsed() { return millis(); }

 void TimerGeek::blink(int Led, long Interval, boolean LedState){
 	led = Led;
 	interval = Interval;
 	ledState = LedState;
 	previousMillis = 0;
 	pinMode(led, OUTPUT);
 	digitalWrite(led, ledState);
 }

 void TimerGeek::blinkFuntion(){
 	unsigned long currentMillis = millis();
 	if (currentMillis - previousMillis >= interval) {
 		previousMillis = currentMillis;
 		fp();
 	}
 }

 void TimerGeek::blinkTimer(){
 	unsigned long currentMillis = millis();
 	if (currentMillis - previousMillis >= interval) {
 		previousMillis = currentMillis;
 		if (ledState == LOW) {
 			ledState = HIGH;
 		} 
 		else {
 			ledState = LOW;
 		}
 		digitalWrite(led, ledState);
 	}
 }

 void TimerGeek::funtion(long _interval, void (* _fp)(), boolean _state){
 	interval = _interval;
 	fp =  _fp; 	
 	state = _state;
 	if (_state == false){
 		previousMillis = 0; 		
 	}
 	else{
 		previousMillis = _interval;
 	}
 }
 void TimerGeek::setInterval(long _interval){
 	interval = _interval;
 }

 long TimerGeek::getInterval(){
 	return interval;
 }

 void TimerGeek::Stop(){
 	previousMillis = millis();
 }

 void TimerGeek::timerFuntion(){
 	unsigned long currentMillis = millis();
 	if (currentMillis - previousMillis >= interval) {
 		previousMillis = millis();
 		fp();
 	}
 }
 long TimerGeek::howMuchLonger(){
 	if(interval - (millis() - previousMillis) > 0){
 		return interval - (millis() - previousMillis);    
 	}
 	else {
 		return 0;
 	}
 }
 long TimerGeek::howMuchLongerOnce(){
 	if (state == false){
 		return -1;
 	}
 	else {
 		if(interval - (millis() - previousMillis) > 0){
 			return interval - (millis() - previousMillis);    
 		}
 		else {
 			return 0;
 		}
 	}
 }

 void TimerGeek::trigger(){
 	state = true;
 	previousMillis = millis();
 }

 void TimerGeek::timerFuntionOnce(){
 	if (state == true){
 		unsigned long currentMillis = millis();
 		if (currentMillis - previousMillis >= interval) {
 			state = false; 			
 			fp();
 		}
 	}
 }