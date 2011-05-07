/* 
 * File:   CLI.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:49 PM
 */

#ifndef CLI_H
#define	CLI_H

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>

#include "Circuit.h"

class CLI {
public:
    CLI();
    ~CLI();
    
private:
    int argc;
    char argv[10][100];
    Circuit *circuit;

    CLI(CLI &);

    int readCommand(std::istream& stream, bool interactive);
    int parseCommand();
    void requireCircuit();
    void requireNumberOfParameters(int);

    int help();
    int exit();
    int unknownCommand();

    int new_circuit();
    int open_circuit();
    int close_circuit();
    int save_circuit();
    int print_circuit();
    int run_circuit();
    
    int add_component();
    int mod_component();
    int del_component();

    int wire();
    int unwire();

};

#endif	/* CLI_H */

