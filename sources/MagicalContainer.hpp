#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> _container;

    public:
        // Constructors
        MagicalContainer();

        // Main functions
        void addElement(int element);
        void removeElement(int element);
        int size() const;

        // Aid functions
        bool isEmpty() const;
        string toString() const;

        // Getters
        vector<int> &getContainer() const;

        // Iterators

        class AscendingIterator
        {
        private:
            MagicalContainer& _magicalContainer;
            vector<int> ascendingList;

        public:
            // Constructors
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            // Main functions
            int* begin();
            int* end();
        };
    };
}

#endif