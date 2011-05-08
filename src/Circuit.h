/* 
 * File:   Circuit.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:52 PM
 */

#ifndef CIRCUIT_H
#define	CIRCUIT_H

#include <iostream>
#include "ComponentList.h"

/**
 * Manages the components and their relations.
 */
class Circuit {
private:
    /**
     * A list of components
     */
    ComponentList components;

public:
    /**
     * Inititalizes an empty circuit
     */
    Circuit() {};
    /**
     * Frees the components in the circuit
     */
    ~Circuit();

    /**
     * Gets the ID of the given Component pointer
     *
     * @param component the component
     * @return the ID of the parameter component
     */
    unsigned getComponentID(Component *component);

    /**
     * Adds a component to the circuit.
     *
     * The possible components are: AND, NAND, OR, NOR, LED, Node, Inverter,
     * Switch, Positive, Negative
     *
     * @param component_class the class of the component to be added
     */
    void add_component(const char* component_class);
    /**
     * Remove a component from the circuit
     *
     * @param component_id the id of the component to be removed
     */
    void del_component(unsigned component_id);
    /**
     * Modifies the given component's settings
     *
     * @param component_id the id of the component to be modified
     * @param parameters the new settings
     */
    void mod_component(unsigned component_id, char *parameters);

    /**
     * Wires two component
     *
     * Wires the first parameter's output to the second parameter's input.
     *
     * @param component_output the source component
     * @param component_input the target component
     */
    void wire(unsigned component_output, unsigned component_input);
    /**
     * Unwires two component
     * 
     * Unwires the first parameter's output from the second parameter's input.
     * 
     * @param component_output the source component
     * @param component_input the target component
     */
    void unwire(unsigned component_output, unsigned component_input);

    /**
     * Prints the circuit to the given output stream
     *
     * @param output_stream the output stream
     */
    void print(std::ostream &output_stream);
    /**
     * Runs the circuit
     *
     *
     */
    void run();

    /**
     * Writes the circuit to an output stream.
     *
     * This will serialize the circuit and writes out the text representation of
     * it. The circuit will be easily backed up from its text.
     *
     * @param os output stream
     * @param circuit the circuit
     */
    friend std::ostream &operator<<(std::ostream &os, Circuit *circuit);
};

#endif	/* CIRCUIT_H */
