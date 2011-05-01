/* 
 * File:   Node.cpp
 * Author: balazs
 * 
 * Created on May 1, 2011, 10:00 PM
 */

#include "Node.h"

bool Node::getValue(){
    if(inputs.getSize() == 0)
        return false;

    return inputs[0]->getValue();
}

const char *Node::getName(){
    return "Node";
}