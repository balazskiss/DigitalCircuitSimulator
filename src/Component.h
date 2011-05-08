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

/**
 * Receives digital sign to its input(s) and sends digital sign to its output(s).
 *
 * This is an abstract class. All of the components derive from this.
 */
class Component {
private:
    /**
     * The parent circuit of the component.
     */
    Circuit *circuit;
    /**
     * Number of maximum inputs
     */
    int max_inputs;
    /**
     * Number of maximum outputs
     */
    int max_outputs;
    /**
     * A locked component cannot be asked for its value
     */
    bool locked;
    
public:
    /**
     * Initializes the private data members
     * @param circuit the parent circuit
     * @param max_inputs number of maximum inputs
     * @param max_outputs number of maximum outputs
     */
    Component(Circuit *circuit, int max_inputs, int max_outputs);
    /**
     * Virtual destruktor
     */
    virtual ~Component() { } ;

    /**
     * Connects a component to the input
     * @param component this component's output will be sent to the input
     */
    void connectToInput(Component *component);
    /**
     * onnects a component to the output
     * @param component the output will be sent to this component's input
     */
    void connectToOutput(Component *component);
    /**
     * Disconnects a component from the input
     * @param component the component on the input
     */
    void disconnectFromInput(Component *component);
    /**
     * Disconnects a component from the output
     * @param component the component on the output
     */
    void disconnectFromOutput(Component *component);

    /**
     * Returns the ID of the component
     * @return the ID of this component
     */
    unsigned getID() { return circuit->getComponentID(this); };
    /**
     * Returns the number of components on the input
     * @return the number of components on the input
     */
    unsigned getNumberOfInputs(){ return inputs.getSize(); };
    /**
     * Gets the nth input component
     * @param index n
     * @return a pointer to the component
     */
    Component *getInputComponent(unsigned index) { return inputs[index]; };
    /**
     * Prints the component to the standard output
     *
     * TODO: this should use any output stream
     */
    void print();

    /**
     * Gets the output digital sign
     * @return the output digital sign
     */
    virtual bool getValue() = 0;
    /**
     * Gets the name of the component
     * @return the name of the component
     */
    virtual const char *getName() = 0;

protected:
    /**
     * List of input components
     */
    ComponentList inputs;
    /**
     * List of output components
     */
    ComponentList outputs;

    /**
     * Prints the input components' ID to the stdout
     */
    void printInput();
    /**
     * Prints the output components' ID to the stdout
     */
    void printOutput();
    /**
     * Locks the component
     * @throws const char * the component is already locked
     */
    void lock();
    /**
     * Unlocks the component
     */
    void unlock();
};

/**
 * Light Emission Diode
 *
 * This is the main output component. When you run a circuit, you will see the
 * list of the LEDs and their states (on or off).
 * It has 1 input.
 */
class LED: public Component {
public:
    LED(Circuit *circuit): Component(circuit, 1, 0) {};
    bool getValue();
    const char *getName();
};

/**
 * Logical OR gate
 *
 * Maximal number of input: any number
 * Maximal number of output: 1
 */
class OR: public Component {
public:
    OR(Circuit *circuit): Component(circuit, -1, 1) {};
    bool getValue();
    const char *getName();
};

/**
 * Logical NOR gate
 *
 * Maximal number of input: any number
 * Maximal number of output: 1
 */
class NOR: public Component {
public:
    NOR(Circuit *circuit): Component(circuit, -1, 1) {};
    bool getValue();
    const char *getName();
};

/**
 * Logical AND gate
 *
 * Maximal number of input: any number
 * Maximal number of output: 1
 */
class AND: public Component{
public:
    AND(Circuit *circuit): Component(circuit, -1, 1) {};
    bool getValue();
    const char *getName();
};

/**
 * Logical NAND gate
 *
 * Maximal number of input: 2
 * Maximal number of output: 1
 */
class NAND: public Component{
public:
    NAND(Circuit *circuit): Component(circuit, 2, 1) {};
    bool getValue();
    const char *getName();
};

/**
 * Negative - low level digital sign
 *
 * Maximal number of input: 0
 * Maximal number of output: 1
 */
class Negative: public Component{
public:
    Negative(Circuit *circuit): Component(circuit, 0, 1) {};
    bool getValue();
    const char *getName();
};

/**
 * Positive - high level digital sign
 *
 * Maximal number of input: 0
 * Maximal number of output: 1
 */
class Positive: public Component{
public:
    Positive(Circuit *circuit): Component(circuit, 0, 1) {};
    bool getValue();
    const char *getName();
};

/**
 * Node - one input, many outputs
 *
 * Maximal number of input: 1
 * Maximal number of output: any number
 */
class Node: public Component{
public:
    Node(Circuit *circuit): Component(circuit, 1, -1) {};
    bool getValue();
    const char *getName();
};

/**
 * Inverts the input digital sign
 *
 * Maximal number of input: 1
 * Maximal number of output: 1
 */
class Inverter: public Component{
public:
    Inverter(Circuit *circuit): Component(circuit, 1, 1) {};
    bool getValue();
    const char *getName();
};


/**
 * Adjustable switch
 *
 * Its value can be adjusted by the user.
 * With CLI you can use: mod [switch_id] [on/off]
 *
 * Maximal number of input: 0
 * Maximal number of output: 1
 */
class Switch: public Component{
public:
    bool value;
    Switch(Circuit *circuit): Component(circuit, 0, 1), value(false) {};
    bool getValue();
    const char *getName();
};


#endif	/* COMPONENT_H */
