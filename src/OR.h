/* 
 * File:   OR.h
 * Author: balazs
 *
 * Created on April 28, 2011, 11:17 AM
 */

#ifndef OR_H
#define	OR_H

#include "Component.h"

class OR: public Component {
public:
    OR(unsigned id): Component(id, -1, 1) {};
    bool getValue();
    const char *getName();
};

#endif	/* OR_H */

