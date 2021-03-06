/* 
 * File:   ComponentList.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:53 PM
 */

#include "ComponentList.h"
#include "Component.h"

ComponentList::ComponentList() : size(0) {
    components = 0;
}

ComponentList::~ComponentList() {
    delete[] components;
}

Component* ComponentList::operator[](int index) const{
    if(index<0 || index>size-1)
        throw("Undefined component index.");
    return components[index];
}

void ComponentList::add(Component *c){
    Component **tmp = new Component *[size+1];
    for(int i=0; i<size; i++)
        tmp[i]=components[i];

    tmp[size++]=c;

    delete[] components;
    components = tmp;
}

void ComponentList::remove(Component *c){
    bool found = false;
    for(int i=0; i<size; i++){
        if(components[i] == c)
            found = true;
        if(found && i!=size-1)
            components[i]=components[i+1];
    }

    if(found)
        size--;
    else
        throw("The given Component pointer is not in the list!");
}

int ComponentList::getSize() const{
    return size;
}