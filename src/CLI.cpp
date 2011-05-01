/* 
 * File:   CLI.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:49 PM
 */

#include "CLI.h"

using namespace std;

CLI::CLI() {
    cout << "DigitalCircuitSimulator CLI Interface" << endl;

    circuit = 0;
    new_circuit();

    //main loop
    while( ! readCommand()) ;
}

CLI::~CLI() {
    delete circuit;
}

int CLI::readCommand(){
    char cmd[1000];

    cout << ">" ;
    argc = 0;

    cin.getline(cmd, 1000);
    stringstream ss(cmd);
    while (ss.good())
        ss >> argv[argc++];

    return parseCommand();
    
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


    return unknownCommand();
}

int CLI::help(){
    cout << "Commands:" << endl;
    cout << "help - prints this message" << endl;
    cout << "exit - Exits the program" << endl;

    return 0;
}

int CLI::exit(){
    return 1;
}


int CLI::unknownCommand(){
    cout << "Unknown command \"" << argv[0] << "\"." << endl;
    return help();
}





int CLI::new_circuit(){
    if(circuit != 0){
        cout << "Close your currently opened circuit first." << endl;
        return 0;
    }

    circuit = new Circuit;
    cout << "New circuit has been created." << endl;
    return 0;
}

int CLI::close_circuit(){
    if(circuit == 0){
        cout << "No circuit is opened." << endl;
        return 0;
    }

    delete circuit;
    circuit = 0;
    return 0;
}

int CLI::open_circuit(){
    return 0;
}
int CLI::save_circuit(){
    if(circuit == 0){
        cout << "No circuit is opened." << endl;
        return 0;
    }
    return 0;
}
int CLI::print_circuit(){
    if(circuit == 0){
        cout << "No circuit is opened." << endl;
        return 0;
    }

    circuit->print();

    return 0;
}
int CLI::run_circuit(){
    if(circuit == 0){
        cout << "No circuit is opened." << endl;
        return 0;
    }
    return 0;
}



int CLI::add_component(){
    if(circuit == 0){
        cout << "No circuit is opened." << endl;
        return 0;
    }

    circuit->add_component(argv[1]);

    return 0;
}
int CLI::mod_component(){
    if(circuit == 0){
        cout << "No circuit is opened." << endl;
        return 0;
    }
    return 0;
}
int CLI::del_component(){
    if(circuit == 0){
        cout << "No circuit is opened." << endl;
        return 0;
    }
    return 0;
}

int CLI::wire(){
    if(circuit == 0){
        cout << "No circuit is opened." << endl;
        return 0;
    }

    if(argc != 3){
        cout << "Bad number of parameters" << endl;
        return 0;
    }

    int c1_i = atoi(argv[1]);
    int c2_i = atoi(argv[2]);

    if((c1_i * c2_i) == 0){
        cout << "Please enter a valid component index" << endl;
        return 0;
    }

    c1_i--; c2_i--;
    circuit->wire(c1_i, c2_i);

    return 0;
}