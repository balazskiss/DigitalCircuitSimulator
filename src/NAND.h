/* 
 * File:   NAND.h
 * Author: balazs
 *
 * Created on April 17, 2011, 8:50 PM
 */

#ifndef NAND_H
#define	NAND_H

#include "Component.h"

class NAND: public Component{
public:
    NAND(unsigned id): Component(id, 2, 1) {};
    bool getValue();
    const char *getName();
};


#endif	/* NAND_H */
