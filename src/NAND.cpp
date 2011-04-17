/* 
 * File:   NAND.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 8:50 PM
 */

#include "NAND.h"

bool NAND::getValue(){
    return false;
}

std::ostream &operator<<(std::ostream &os, Component *c){
    std::cout << "NAND gate" << std::endl;
}