/* 
 * File:   Node.h
 * Author: balazs
 *
 * Created on May 1, 2011, 10:00 PM
 */

#ifndef NODE_H
#define	NODE_H

#include "Component.h"

class Node: public Component{
public:
    Node(unsigned id): Component(id, 1, -1) {};
    bool getValue();
    const char *getName();
};

#endif	/* NODE_H */

