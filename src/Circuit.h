/* 
 * File:   Circuit.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:52 PM
 */

#ifndef CIRCUIT_H
#define	CIRCUIT_H

#include "ComponentList.h"

class Circuit {
public:
    ComponentList components;
    
    bool wire(Component *, Component *);
    void unwire(Component *, Component*);
    

};

#endif	/* CIRCUIT_H */
