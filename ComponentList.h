/* 
 * File:   ComponentList.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:53 PM
 */

#ifndef COMPONENTLIST_H
#define	COMPONENTLIST_H

class Component;

class ComponentList {
public:
    ComponentList();
    ~ComponentList();

    void add(Component *);
    void remove(Component *);
    int getSize() const;


private:
    Component **components;
    int size;
};

#endif	/* COMPONENTLIST_H */
