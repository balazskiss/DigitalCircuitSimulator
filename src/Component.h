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
public:
    void connectToInput(Component *);
    void connectToOutput(Component *);
    virtual bool getValue() = 0;

protected:
    ComponentList inputs;
    ComponentList outputs;
};



#endif	/* COMPONENT_H */
