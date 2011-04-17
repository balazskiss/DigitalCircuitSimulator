/* 
 * File:   Component.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:54 PM
 */

#ifndef COMPONENT_H
#define	COMPONENT_H

#include "ComponentList.h"

class Component {
public:
    Component();
    Component(const Component& orig);
    virtual ~Component();
    bool getValue();
private:
    ComponentList inputs;
    ComponentList outputs;

};

#endif	/* COMPONENT_H */
