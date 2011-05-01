/* 
 * File:   LED.h
 * Author: balazs
 *
 * Created on May 1, 2011, 9:50 PM
 */

#ifndef LED_H
#define	LED_H

#include "Component.h"

class LED: public Component {
public:
    LED(unsigned id): Component(id, 1, 0) {};
    bool getValue();
    const char *getName();
};


#endif	/* LED_H */

