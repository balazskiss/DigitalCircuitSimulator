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
    std::cout << "Input: " <<  std::endl;
    for(int i=0; i<inputs.getSize(); i++)
        
}
void Component::printOutput(){
    std::cout << "Output: " <<  std::endl;
}