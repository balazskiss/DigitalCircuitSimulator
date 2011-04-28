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
public:
    ComponentList components;
    
    bool wire(unsigned, unsigned);
    void unwire(Component *, Component*);
    

};

std::ostream &operator<<(std::ostream &os, Circuit *circuit);

#endif	/* CIRCUIT_H */
