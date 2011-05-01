/* 
 * File:   NAND.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 8:50 PM
 */

#include "NAND.h"

bool NAND::getValue(){
    if(inputs.getSize() < 2)
        return true;
    else
        return ! (inputs[0]->getValue() && inputs[1]->getValue());
}

const char *NAND::getName(){
    return "NAND gate";
}