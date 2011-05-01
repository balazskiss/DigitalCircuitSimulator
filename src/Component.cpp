/* 
 * File:   Component.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:54 PM
 */

#include "Component.h"

void Component::connectToInput(Component *c){
    if((inputs.getSize() < max_inputs) || (max_inputs == -1))
        inputs.add(c);
    else
        throw("Couldn't connect to input.");
}

void Component::connectToOutput(Component *c){
    if((outputs.getSize() < max_outputs) || (max_outputs == -1))
        outputs.add(c);
    else
        throw("Couldn't connect to output.");
}

void Component::printInput(){
    std::cout << "Input: ";
    for(int i=0; i<inputs.getSize(); i++)
        std::cout << '#' << inputs[i]->getID()+1 << ' ';
    std::cout << std::endl;
}
void Component::printOutput(){
    std::cout << "Output: ";
    for(int i=0; i<outputs.getSize(); i++)
        std::cout << '#' << outputs[i]->getID()+1 << ' ';
    std::cout << std::endl;
}

void Component::print(){
    std::cout << this->getName() << std::endl;
    this->printInput();
    this->printOutput();
    std::cout << "Value: " << getValue() << std::endl;
}