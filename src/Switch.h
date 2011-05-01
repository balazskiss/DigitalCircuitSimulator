/* 
 * File:   Switch.h
 * Author: balazs
 *
 * Created on May 1, 2011, 10:00 PM
 */

#ifndef SWITCH_H
#define	SWITCH_H

#include "Component.h"

class Switch: public Component{
public:
    bool value;
    Switch(unsigned id): Component(id, 0, 1) { value=false; };
    bool getValue();
    const char *getName();
};

#endif	/* SWITCH_H */

