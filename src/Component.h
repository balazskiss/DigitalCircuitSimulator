/* 
 * File:   Component.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:54 PM
 */

#ifndef COMPONENT_H
#define	COMPONENT_H

#include <iostream>
#include "ComponentList.h"

class Component {
private:
    unsigned id;
    int max_inputs;
    int max_outputs;
    
public:
    Component(unsigned id, int max_inputs, int max_outputs) {
        this->id = id;
        this->max_inputs = max_inputs;
        this->max_outputs = max_outputs;
    };

    void connectToInput(Component *);
    void connectToOutput(Component *);
    virtual bool getValue() = 0;
    void print();

    virtual const char *getName() = 0;
    unsigned getID() { return id; };

protected:
    ComponentList inputs;
    ComponentList outputs;

    void printInput();
    void printOutput();
};



#endif	/* COMPONENT_H */
