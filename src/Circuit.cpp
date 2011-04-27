/* 
 * File:   Circuit.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:52 PM
 */

#include "Circuit.h"

std::ostream &operator<<(std::ostream &os, Circuit *circuit){
    for(int i=0; i<circuit->components.getSize(); i++)
        os << (NAND*)circuit->components[i];
    return os;
}
