/* 
 * File:   LED.cpp
 * Author: balazs
 * 
 * Created on May 1, 2011, 9:50 PM
 */

#include "LED.h"

bool LED::getValue(){
    if(inputs.getSize() == 0)
        return false;
    
    return inputs[0]->getValue();
}

const char *LED::getName(){
    return "LED";
}