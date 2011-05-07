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

Circuit::~Circuit(){
    for(int i=0;i<components.getSize();i++)
        delete components[i];
}

std::ostream &operator<<(std::ostream &os, Circuit *circuit){
    for(int i=0; i<circuit->components.getSize(); i++){
        os << "add " << circuit->components[i]->getName() << std::endl;
    }

    for(int i=0; i<circuit->components.getSize(); i++){
        for(int j=0; j< (int) circuit->components[i]->getNumberOfInputs(); j++){
            Component *input = circuit->components[i]->getInputComponent(j);

            os << "wire ";
            os << circuit->getComponentID(input)+1;
            os << " " << i+1 << std::endl;
        }
    }

    return os;
}

unsigned Circuit::getComponentID(Component *component){
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

void Circuit::run(){
    for(int i=0; i<components.getSize(); i++){
        Component *c = components[i];
        if(strcmp(c->getName(), "LED") == 0 ){
            std::cout << "LED (Component #" << c->getID()+1 << "): ";
            if(c->getValue())
                std::cout << "On" << std::endl;
            else
                std::cout << "Off" << std::endl;
        }
    }
}

void Circuit::add_component(const char* component){
    if(strcmp(component, "AND") == 0){
        Component *and_gate = new AND(this);
        components.add(and_gate);

    }else if(strcmp(component, "NAND") == 0){
        Component *nand_gate = new NAND(this);
        components.add(nand_gate);

    }else if(strcmp(component, "OR") == 0){
        Component *or_gate = new OR(this);
        components.add(or_gate);

    }else if(strcmp(component, "NOR") == 0){
        Component *nor_gate = new NOR(this);
        components.add(nor_gate);

    }else if(strcmp(component, "LED") == 0){
        Component *led = new LED(this);
        components.add(led);

    }else if(strcmp(component, "Node") == 0){
        Component *node = new Node(this);
        components.add(node);

    }else if(strcmp(component, "Inverter") == 0){
        Component *inverter = new Inverter(this);
        components.add(inverter);

    }else if(strcmp(component, "Switch") == 0){
        Component *switch_c = new Switch(this);
        components.add(switch_c);

    }else if(strcmp(component, "Positive") == 0){
        Component *positive = new Positive(this);
        components.add(positive);

    }else if(strcmp(component, "Negative") == 0){
        Component *negative = new Negative(this);
        components.add(negative);

    }else{
        throw("Unknown component.");
    }
}

void Circuit::del_component(unsigned c_id){
    Component *c = components[c_id];

    components.remove(c);
}

void Circuit::mod_component(unsigned c_id, char *setting){
    Component *c = components[c_id];

    if(strcmp(c->getName(), "Switch") == 0){
        Switch *sw = static_cast<Switch *>(c);
        if(strcmp(setting, "on") == 0)
            sw->value = true;
        else if(strcmp(setting, "off") == 0)
            sw->value = false;
        else
            throw("Please type \'on\' or \'off\'.");
    }else{
        throw("Immutable component.");
    }
}

bool Circuit::wire(unsigned c1_id, unsigned c2_id){
    Component *c1 = components[c1_id];
    Component *c2 = components[c2_id];

    c1->connectToOutput(c2);
    c2->connectToInput(c1);

    return true;
}
void Circuit::unwire(unsigned c1_id, unsigned c2_id){
    Component *c1 = components[c1_id];
    Component *c2 = components[c2_id];

    c1->disconnectFromOutput(c2);
    c2->disconnectFromInput(c1);
}