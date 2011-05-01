/* 
 * File:   Positive.h
 * Author: balazs
 *
 * Created on May 1, 2011, 10:01 PM
 */

#ifndef POSITIVE_H
#define	POSITIVE_H

#include "Component.h"

class Positive: public Component{
public:
    Positive(unsigned id): Component(id, 0, 1) {};
    bool getValue();
    const char *getName();
};

#endif	/* POSITIVE_H */

