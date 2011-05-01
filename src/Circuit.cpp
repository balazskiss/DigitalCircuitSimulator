/* 
 * File:   Circuit.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:52 PM
 */

#include "Circuit.h"
#include "Component.h"
#include "NAND.h"
#include "OR.h"

/*std::ostream &operator<<(std::ostream &os, Circuit *circuit){
    for(int i=0; i<circuit->components.getSize(); i++){
        os << std::endl;
        os << "Component #" << i+1 << std::endl;
        circuit->components[i]->print();
    }
    return os;
}*/

void Circuit::print(){
    for(int i=0; i<components.getSize(); i++){
        std::cout << std::endl;
        std::cout << "Component #" << i+1 << std::endl;
        components[i]->print();
    }
}

unsigned Circuit::getNextComponentID(){
    return components.getSize();
}

void Circuit::add_component(const char* component){
    if(strcmp(component, "NAND") == 0){
        Component *nand = new NAND(getNextComponentID());
        components.add(nand);

    }else if(strcmp(component, "OR") == 0){
        Component *or_gate = new OR(getNextComponentID());
        components.add(or_gate);

    }else{
        throw("Unknown component.");
    }
}

bool Circuit::wire(unsigned c1_id, unsigned c2_id){
    Component *c1 = components[c1_id];
    Component *c2 = components[c2_id];

    c1->connectToOutput(c2);
    c2->connectToInput(c1);

    return true;
}
void Circuit::unwire(Component *c1, Component*c2){

}