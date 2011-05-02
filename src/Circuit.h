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

public:
    unsigned getComponentID(Component *);
    void add_component(const char*);
    void del_component(unsigned);
    void mod_component(unsigned, char *);
    
    bool wire(unsigned, unsigned);
    void unwire(unsigned, unsigned);
    
    void print();
    void run();

    friend std::ostream &operator<<(std::ostream &os, Circuit *circuit);
};

#endif	/* CIRCUIT_H */
