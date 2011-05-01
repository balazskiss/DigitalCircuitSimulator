/* 
 * File:   OR.cpp
 * Author: balazs
 * 
 * Created on April 28, 2011, 11:17 AM
 */

#include "OR.h"

bool OR::getValue(){
    bool val = false;
    for(int i=0; i<inputs.getSize(); i++){
        val = inputs[i]->getValue() || val;
    }
    return val;
}

const char *OR::getName(){
    return "OR";
}