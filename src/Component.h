/* 
 * File:   Component.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:54 PM
 */

#ifndef COMPONENT_H
#define	COMPONENT_H

#include <iostream>
#include "Circuit.h"
#include "ComponentList.h"

class Component {
private:
    Circuit *circuit;
    int max_inputs;
    int max_outputs;
    
public:
    Component(Circuit *circuit, int max_inputs, int max_outputs) {
        this->circuit = circuit;
        this->max_inputs = max_inputs;
        this->max_outputs = max_outputs;
    };
    virtual ~Component() { std::cout << "destruktor!!!" <<std::endl ;} ;

    void connectToInput(Component *);
    void connectToOutput(Component *);
    void disconnectFromInput(Component *);
    void disconnectFromOutput(Component *);
    
    virtual bool getValue() = 0;
    void print();

    virtual const char *getName() = 0;
    unsigned getID() { return circuit->getComponentID(this); };
    unsigned getNumberOfInputs(){ return inputs.getSize(); };
    Component *getInputComponent(unsigned id) { return inputs[id]; };

protected:
    ComponentList inputs;
    ComponentList outputs;

    void printInput();
    void printOutput();
};

//LED
class LED: public Component {
public:
    LED(Circuit *circuit): Component(circuit, 1, 0) {};
    bool getValue();
    const char *getName();
};

//OR
class OR: public Component {
public:
    OR(Circuit *circuit): Component(circuit, -1, 1) {};
    bool getValue();
    const char *getName();
};

//NOR
class NOR: public Component {
public:
    NOR(Circuit *circuit): Component(circuit, -1, 1) {};
    bool getValue();
    const char *getName();
};

//AND
class AND: public Component{
public:
    AND(Circuit *circuit): Component(circuit, -1, 1) {};
    bool getValue();
    const char *getName();
};

//NAND
class NAND: public Component{
public:
    NAND(Circuit *circuit): Component(circuit, 2, 1) {};
    bool getValue();
    const char *getName();
};

//Negative
class Negative: public Component{
public:
    Negative(Circuit *circuit): Component(circuit, 0, 1) {};
    bool getValue();
    const char *getName();
};

//Positive
class Positive: public Component{
public:
    Positive(Circuit *circuit): Component(circuit, 0, 1) {};
    bool getValue();
    const char *getName();
};

//Node
class Node: public Component{
public:
    Node(Circuit *circuit): Component(circuit, 1, -1) {};
    bool getValue();
    const char *getName();
};

//Inverter
class Inverter: public Component{
public:
    Inverter(Circuit *circuit): Component(circuit, 1, 1) {};
    bool getValue();
    const char *getName();
};


//Switch
class Switch: public Component{
public:
    bool value;
    Switch(Circuit *circuit): Component(circuit, 0, 1), value(false) {};
    bool getValue();
    const char *getName();
};


#endif	/* COMPONENT_H */
