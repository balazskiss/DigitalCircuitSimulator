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
    Circuit();
    Circuit(const Circuit& orig);
    virtual ~Circuit();

    bool wire(Component *, Component *);
    void writeToFile(const char *);

private:
    ComponentList components;
};

#endif	/* CIRCUIT_H */
