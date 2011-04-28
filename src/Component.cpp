/* 
 * File:   Component.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:54 PM
 */

#include "Component.h"

void Component::connectToInput(Component *c){
    inputs.add(c);
}

void Component::connectToOutput(Component *c){
    outputs.add(c);
}

void Component::printInput(){
    std::cout << "Input: ";
    for(int i=0; i<inputs.getSize(); i++)
        std::cout << inputs[i] << ' ';
    std::cout << std::endl;
}
void Component::printOutput(){
    std::cout << "Output: ";
    for(int i=0; i<outputs.getSize(); i++)
        std::cout << outputs[i] << ' ';
    std::cout << std::endl;
}