/* 
 * File:   Negative.h
 * Author: balazs
 *
 * Created on May 1, 2011, 10:01 PM
 */

#ifndef NEGATIVE_H
#define	NEGATIVE_H

#include "Component.h"

class Negative: public Component{
public:
    Negative(unsigned id): Component(id, 0, 1) {};
    bool getValue();
    const char *getName();
};

#endif	/* NEGATIVE_H */

