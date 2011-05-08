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

/**
 * Command Line Interface
 */
class CLI {
public:
    /**
     * Initializes a new CLI with an empty Circuit
     */
    CLI();

    /**
     * CLI Destructor
     */
    ~CLI();
    
private:
    /**
     * Number of arguments
     */
    int argc;
    /**
     * Array of the given arguments
     * argv[0] is the name of the command
     */
    char argv[10][100];
    /**
     * The associated Circuit
     */
    Circuit *circuit;

    
    CLI(CLI &);

    /**
     * Reads a command from input stream
     *
     * @param stream the input stream
     * @param interactive whether to display the '> ' prompt
     * @return
     */
    int readCommand(std::istream& stream, bool interactive);
    /**
     * Parses the entered command
     * @return exit code
     */
    int parseCommand();
    /**
     * Requires an opened circuit
     *
     * @throws const char* no opened circuit
     */
    void requireCircuit();
    /**
     * Requires a number of arguments
     *
     * If not enough parametes specified throws an error.
     *
     * @param n the number of required arguments
     * @throws const char * not enough parameters specified
     */
    void requireNumberOfParameters(int n);

    /**
     * Displays the help message
     * @return exit code
     */
    int help();
    /**
     * Exits the program
     *
     * This method return an exit code 1.
     *
     * @return exit code
     */
    int exit();
    /**
     * Handles unknown commands
     * @return exit code
     */
    int unknownCommand();

    /**
     * Starts a new circuit.
     * @return exit code
     * @throws const char * a circuit already opened
     */
    int new_circuit();
    /**
     * Loads  a circuit from file
     * @return exit code
     */
    int open_circuit();
    /**
     * Closes current circuit
     * @return  exit_code
     */
    int close_circuit();
    /**
     * Saves current circuit to file
     * @return  exit_code
     */
    int save_circuit();
    /**
     * Prints current circuit to the stdout
     * @return  exit_code
     */
    int print_circuit();
    /**
     * Runs the current circuit
     * This will print the LEDs and their states (on/off) to the stdout
     * @return  exit_code
     */
    int run_circuit();

    /**
     * Adds a component to the circuit
     * @return  exit_code
     */
    int add_component();
    /**
     * Modifies a component in the circuit
     * @return  exit_code
     */
    int mod_component();
    /**
     * Removes a component in the circuit
     * @return  exit_code
     */
    int del_component();

    /**
     * Wires two components
     * @return exit_code
     */
    int wire();
    /**
     * Unwires two components.
     * @return exit_code
     */
    int unwire();

};

#endif	/* CLI_H */

