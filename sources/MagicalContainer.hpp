#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>
#include "MyIterator.hpp"

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

        // Iterators

        class AscendingIterator
        {
        private:
            MagicalContainer& _magicalContainer;
            MyIterator<int> _ascendingIterator;

        public:
            // Constructors
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator();
            ~AscendingIterator();

            // Main functions
            MyIterator<int> &begin();
            MyIterator<int> &end();
        };
    };
}

#endif