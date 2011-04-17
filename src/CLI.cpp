/* 
 * File:   CLI.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:49 PM
 */

#include "CLI.h"

using namespace std;

CLI::CLI() {
    cout << "DigitalWorks CLI Interface" << endl;

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
    cout << "Unknown command \"" << argv[0] << "\"" << endl;
    return help();
}


int CLI::new_circuit(){

    if(circuit != 0){
        cout << "Close your currently opened circuit first." << endl;
        return 0;
    }

    circuit = new Circuit;
    cout << "New circuit has been created" << endl;
    return 0;
}

int CLI::close_circuit(){

    if(circuit == 0){
        cout << "No circuit is opened." << endl;
        return 0;
    }

    circuit = 0;
    return 0;
}