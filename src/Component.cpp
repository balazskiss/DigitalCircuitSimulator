/* 
 * File:   Component.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:54 PM
 */

#include "Component.h"

Component::Component(Circuit *circuit, int max_inputs, int max_outputs) {
        this->circuit = circuit;
        this->max_inputs = max_inputs;
        this->max_outputs = max_outputs;
        locked = false;
    };

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

void Component::disconnectFromInput(Component *c){
    //TODO: error handling
    inputs.remove(c);
}

void Component::disconnectFromOutput(Component *c){
    //TODO: error handling
    outputs.remove(c);
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

void Component::lock(){
    if(locked)
        throw("Component locked!");
    locked = true;
}
void Component::unlock(){
    locked = false;
}



//LED
bool LED::getValue(){
    if(inputs.getSize() == 0)
        return false;

    return inputs[0]->getValue();
}

const char *LED::getName(){
    return "LED";
}

//AND
bool AND::getValue(){
    if(inputs.getSize() < 2)
        return false;

    bool val = true;
    for(int i=0; i<inputs.getSize(); i++){
        val = inputs[i]->getValue() && val;
    }
    return val;
}

const char *AND::getName(){
    return "AND";
}

//NAND
bool NAND::getValue(){
    if(inputs.getSize() < 2)
        return true;
    else
        return ! (inputs[0]->getValue() && inputs[1]->getValue());
}

const char *NAND::getName(){
    return "NAND";
}

//OR
bool OR::getValue(){
    lock();
    bool val = false;
    for(int i=0; i<inputs.getSize(); i++){
        val = inputs[i]->getValue() || val;
    }
    unlock();
    return val;
}

const char *OR::getName(){
    return "OR";
}

//NOR
bool NOR::getValue(){
    bool val = false;
    for(int i=0; i<inputs.getSize(); i++){
        val = inputs[i]->getValue() || val;
    }
    return ! val;
}

const char *NOR::getName(){
    return "NOR";
}

//Negative
bool Negative::getValue(){
    return false;
}

const char *Negative::getName(){
    return "Negative";
}

//Positive
bool Positive::getValue(){
    return true;
}

const char *Positive::getName(){
    return "Positive";
}

//Switch
bool Switch::getValue(){
    return value;
}

const char *Switch::getName(){
    return "Switch";
}

//Node
bool Node::getValue(){
    if(inputs.getSize() == 0)
        return false;

    return inputs[0]->getValue();
}

const char *Node::getName(){
    return "Node";
}


//Inverter
bool Inverter::getValue(){
    if(inputs.getSize() == 0)
        return true;

    return ! inputs[0]->getValue();
}

const char *Inverter::getName(){
    return "Inverter";
}
