/* 
 * File:   Circuit.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:52 PM
 */

#include <string.h>
#include <stdlib.h>

#include "Circuit.h"
#include "Component.h"
#include "NAND.h"
#include "OR.h"
#include "LED.h"
#include "Node.h"
#include "Switch.h"
#include "Positive.h"
#include "Negative.h"

std::ostream &operator<<(std::ostream &os, Circuit *circuit){
    for(int i=0; i<circuit->components.getSize(); i++){
        os << "add " << circuit->components[i]->getName() << std::endl;
    }

    for(int i=0; i<circuit->components.getSize(); i++){
        for(int j=0; j< (int) circuit->components[i]->getNumberOfInputs(); j++){
            Component *input = circuit->components[i]->getInputComponent(j);

            os << "wire ";
            os << circuit->getIndexForComponent(input)+1;
            os << " " << i+1 << std::endl;
        }
    }

    return os;
}

unsigned Circuit::getIndexForComponent(Component *component){
    for(int i=0; components.getSize(); i++){
        if(components[i] == component)
            return i;
    }
    return 0;
}

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

    }else if(strcmp(component, "LED") == 0){
        Component *led = new LED(getNextComponentID());
        components.add(led);

    }else if(strcmp(component, "Node") == 0){
        Component *node = new Node(getNextComponentID());
        components.add(node);

    }else if(strcmp(component, "Switch") == 0){
        Component *switch_c = new Switch(getNextComponentID());
        components.add(switch_c);

    }else if(strcmp(component, "Positive") == 0){
        Component *positive = new Positive(getNextComponentID());
        components.add(positive);

    }else if(strcmp(component, "Negative") == 0){
        Component *negative = new Negative(getNextComponentID());
        components.add(negative);

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