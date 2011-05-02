/* 
 * File:   ComponentList.cpp
 * Author: balazs
 * 
 * Created on April 17, 2011, 2:53 PM
 */

#include "ComponentList.h"

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

    tmp[size]=c;
    size++;

    delete[] components;
    components = tmp;
}

void ComponentList::remove(Component *c){
    bool pull = false;
    for(int i=0; i<size; i++){
        if(components[i] == c)
            pull = true;
        if(pull && i!=size-1)
            components[i]=components[i+1];
    }

    size--;
}

int ComponentList::getSize() const{
    return size;
}