/* 
 * File:   CLI.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:49 PM
 */

#ifndef CLI_H
#define	CLI_H

#include <iostream>
#include <string.h>

#include "Circuit.h"

class CLI {
public:
    CLI();
    CLI(const CLI& orig);
    virtual ~CLI();
    
private:
    Circuit *circuit;

    void readCommand();
    void getParam(const char *, int, char *);

    void help(const char *);
    void save(const char *);
    void exit(const char *);
    void add(const char *);
    void unknownCommand(const char *);

};

#endif	/* CLI_H */

