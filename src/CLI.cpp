/* 
 * File:   CLI.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:49 PM
 */

#include "CLI.h"
#include <fstream>

using namespace std;

CLI::CLI() {
    cout << "DigitalCircuitSimulator CLI Interface" << endl;

    circuit = 0;
    new_circuit();

    //main loop
    while(true){
        int return_value = 0;
        
        try{
            readCommand(cin, true);
            return_value = parseCommand();
        }
        catch(const char *str){
            std::cout << str << std::endl;
        }

        if(return_value) break;
    }
}

CLI::~CLI() {
    delete circuit;
}

int CLI::readCommand(std::istream& stream, bool interactive){
    char cmd[1000];

    if(interactive)
        cout << "> " ;

    argc = 0;

    stream.getline(cmd, 1000);
    stringstream ss(cmd);
    while (ss.good())
        ss >> argv[argc++];

    return 0;
}

int CLI::parseCommand(){
    if(strcmp(argv[0], "help") == 0)
        return help();
    if(strcmp(argv[0], "exit") == 0)
        return exit();

    if(strcmp(argv[0], "new") == 0)
        return new_circuit();
    if(strcmp(argv[0], "close") == 0)
        return close_circuit();
    if(strcmp(argv[0], "open") == 0)
        return open_circuit();
    if(strcmp(argv[0], "save") == 0)
        return save_circuit();
    if(strcmp(argv[0], "print") == 0)
        return print_circuit();
    if(strcmp(argv[0], "run") == 0)
        return run_circuit();

    if(strcmp(argv[0], "add") == 0)
        return add_component();
    if(strcmp(argv[0], "mod") == 0)
        return mod_component();
    if(strcmp(argv[0], "del") == 0)
        return del_component();

    if(strcmp(argv[0], "wire") == 0)
        return wire();
    if(strcmp(argv[0], "unwire") == 0)
        return unwire();


    return unknownCommand();
}

void CLI::requireCircuit(){
    if(circuit == 0)
        throw("No circuit is opened.");
}
void CLI::requireNumberOfParameters(int n){
    if(argc != n)
        throw("Bad number of parameters");
}

int CLI::help(){
    cout << "Commands:" << endl;
    cout << "help - Prints this message" << endl;
    cout << "exit - Exits the program" << endl;
    cout << "new - Starts an empty circuit" << endl;
    cout << "close - Closes the currently opened circuit" << endl;
    cout << "open [example.dc] - Opens a circuit from file" << endl;
    cout << "save [example.dc] - Saves the circuit to file" << endl;
    cout << "print - Prints the components' details" << endl;
    cout << "run - Runs the circuit (simulate)" << endl;
    cout << "add [component_type] - Adds a component to the circuit" << endl;
    cout << "    Possible components types are: AND, NAND, OR, NOR, LED, Node, Inverter, Switch, Positive, Negative" << endl;
    cout << "mod [component_index] [settings] - Modifies a component's settings" << endl;
    cout << "del [component_index] - Removes a component from the circuit" << endl;
    cout << "wire [component_index] [component_index] - Wires two components" << endl;
    cout << "unwire [component_index] [component_index] - Unwires two components" << endl;

    return 0;
}

int CLI::exit(){
    cout << "Bye-bye" << endl;
    return 1;
}


int CLI::unknownCommand(){
    throw("Unknown command. For available commands type help.");
    return 0;
}





int CLI::new_circuit(){
    if(circuit != 0)
        throw("Close your currently opened circuit first.");

    circuit = new Circuit;
    cout << "New circuit has been created." << endl;

    return 0;
}

int CLI::close_circuit(){
    requireCircuit();

    delete circuit;
    circuit = 0;
    
    return 0;
}

int CLI::open_circuit(){
    if(circuit != 0)
        throw("Close your currently opened circuit first.");
    requireNumberOfParameters(2);

    circuit = new Circuit;

    ifstream infile;
    infile.open(argv[1]);
    if (!infile)
        throw("Unable to open file");
    while(infile.good()){

        try{
            readCommand(infile, false);
            parseCommand();
        }
        catch(char *){
            ; //be quiet
        }
    }
    infile.close();

    return 0;
}
int CLI::save_circuit(){
    requireCircuit();

    ofstream outfile;
    outfile.open(argv[1]);
    outfile << circuit;
    outfile.close();

    return 0;
}
int CLI::print_circuit(){
    requireCircuit();

    circuit->print(cout);

    return 0;
}
int CLI::run_circuit(){
    requireCircuit();

    circuit->run();

    return 0;
}



int CLI::add_component(){
    requireCircuit();

    circuit->add_component(argv[1]);

    return 0;
}
int CLI::mod_component(){
    requireCircuit();
    requireNumberOfParameters(3);

    int c_id = atoi(argv[1]);

    circuit->mod_component(c_id-1, argv[2]);

    return 0;
}
int CLI::del_component(){
    requireCircuit();

    int c_id = atoi(argv[1]);

    circuit->del_component(c_id-1);

    return 0;
}

int CLI::wire(){
    requireCircuit();
    requireNumberOfParameters(3);

    int c1_i = atoi(argv[1]);
    int c2_i = atoi(argv[2]);

    if((c1_i * c2_i) == 0)
        throw("Please enter a valid component index");

    c1_i--; c2_i--;
    circuit->wire(c1_i, c2_i);

    return 0;
}

int CLI::unwire(){
    requireCircuit();
    requireNumberOfParameters(3);

    int c1_i = atoi(argv[1]);
    int c2_i = atoi(argv[2]);

    if((c1_i * c2_i) == 0)
        throw("Please enter a valid component index");

    c1_i--; c2_i--;
    circuit->unwire(c1_i, c2_i);

    return 0;
}