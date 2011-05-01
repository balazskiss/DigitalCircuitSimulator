/* 
 * File:   Circuit.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:52 PM
 */

#ifndef CIRCUIT_H
#define	CIRCUIT_H

#include <iostream>
#include "ComponentList.h"

class Circuit {
private:
    ComponentList components;
    unsigned getNextComponentID();
public:
    void add_component(const char*);
    
    bool wire(unsigned, unsigned);
    void unwire(Component *, Component *);
    
    void print();
};

//std::ostream &operator<<(std::ostream &os, Circuit *circuit);

#endif	/* CIRCUIT_H */
