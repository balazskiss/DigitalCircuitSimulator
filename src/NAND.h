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
    bool getValue();

};


std::ostream &operator<<(std::ostream &os, NAND *c);

#endif	/* NAND_H */

