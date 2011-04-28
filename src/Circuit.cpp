/* 
 * File:   Circuit.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:52 PM
 */

#include "Circuit.h"
#include "Component.h"

std::ostream &operator<<(std::ostream &os, Circuit *circuit){
    for(int i=0; i<circuit->components.getSize(); i++){
        os << std::endl;
        os << "Component #" << i+1 << std::endl;
        circuit->components[i]->print();
    }
    return os;
}

bool Circuit::wire(unsigned c1_i, unsigned c2_i){
    Component *c1 = components[c1_i];
    Component *c2 = components[c2_i];

    c1->connectToOutput(c2);
    c2->connectToInput(c1);

    return true;
}
void Circuit::unwire(Component *c1, Component*c2){

}