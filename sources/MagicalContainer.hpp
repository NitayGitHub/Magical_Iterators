#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "MyIterator.hpp"
#include "MyIterator.cpp"

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> _container;
        vector<int> ascendingList;

    public:
        // Main functions
        void addElement(int element);
        void removeElement(int element);
        int size() const;

        // Aid functions
        bool isEmpty() const;
        string toString() const;

        // Getters
        vector<int> &getContainer() const;
        vector<int> &getAscendingList() const;

        // Iterators

        class AscendingIterator
        {
        private:
            vector<int> &ascendingList;

        public:
            // Constructors
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            // Main functions
            MyIterator<int> begin();
            MyIterator<int> end();
        };
    };
}

#endif