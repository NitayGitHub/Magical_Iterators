#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>
#include "AscendingIterator.hpp"

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        list<int> _container;

    public:
        // Constructors
        MagicalContainer();

        // Main functions
        void addElement(int element);
        void removeElement(int element);
        int size() const;

        // Operators
        bool operator==(const MagicalContainer &other) const;

        // Aid functions
        bool isEmpty() const;
        string toString() const;

        // Getters
        list<int> &getContainer() const;
    };
}

#endif