/* 
 * File:   OR.cpp
 * Author: balazs
 * 
 * Created on April 28, 2011, 11:17 AM
 */

#include "OR.h"

bool OR::getValue(){
    return false;
}

void OR::print(){
    std::cout << "OR gate" << std::endl;
    printInput();
    printOutput();
}