/* 
 * File:   ComponentList.h
 * Author: balazs
 *
 * Created on April 17, 2011, 2:53 PM
 */

#ifndef COMPONENTLIST_H
#define	COMPONENTLIST_H

class Component;

/**
 * Dynamic array of Components.
 */
class ComponentList {
public:
    /**
     * Initializes an empty ComponentList
     */
    ComponentList();
    /**
     * Frees the stored Component pointers
     */
    ~ComponentList();


    /**
     * Adds a Component pointer to the array
     *
     * @param component A pointer to a Component which will be added to the list
     */
    void add(Component *component);
    /**
     * Removes a Component pointer from the array
     *
     * If the same Component pointer is in the array more than once,
     * the first occurence will be removed.
     *
     * @param component A pointer to a Component which will be removed from the list
     * @throws const char*  The given Component * is not in the list
     */
    void remove(Component *component);
    /**
     * Returns the current size of the array
     *
     * @return size of the array
     */
    int getSize() const;

    /**
     * Returns the nth Component pointer in the array
     *
     * @param index the index of the desired Component pointer
     * @return the indexed Component pointer
     */
    Component* operator[](int index) const;

private:
    /**
     * An array of Component pointers
     *
     * @see operator[]
     */
    Component **components;
    /**
     * The current size of the array
     *
     * @see getSize
     */
    int size;
};

#endif	/* COMPONENTLIST_H */
