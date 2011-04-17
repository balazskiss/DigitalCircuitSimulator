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

    circuit = new Circuit;
    cout << "New circuit has been created" << endl;

    readCommand();
}

CLI::CLI(const CLI& orig) {
}

CLI::~CLI() {
    delete circuit;
}

void CLI::readCommand(){
    char cmd[100];
    cout << "> ";
    cin >> cmd;

    if(strcmp(cmd, "help") == 0)
        help(cmd);
    else if(strcmp(cmd, "exit") == 0)
        exit(cmd);
    else
        unknownCommand(cmd);

}

void CLI::help(const char *cmd){
    cout << "Commands:" << endl;
    cout << "help - prints this message" << endl;
    cout << "exit - Exits the program" << endl;

    readCommand();
}
void CLI::save(const char *cmd){

}
void CLI::exit(const char *cmd){

}
void CLI::add(const char *cmd){

}

void CLI::unknownCommand(const char *cmd){
    cout << "Unknown command \"" << cmd << "\"" << endl;
    help(cmd);
}