#ifndef ASCENDINGITERATOR_H
#define ASCENDINGITERATOR_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>
#include "MagicalContainer.hpp"
#include "MyIterator.hpp"

using namespace std;

namespace ariel
{
    class AscendingIterator
    {
    private:
        MagicalContainer &_magicalContainer;
        MyIterator<int> _ascendingIterator;

    public:
        // Constructors
        AscendingIterator(MagicalContainer &container);
        AscendingIterator(const AscendingIterator &other);
        ~AscendingIterator();

        // Operators
        AscendingIterator &operator=(AscendingIterator &other);
        bool &operator==(AscendingIterator &other);
        bool &operator!=(AscendingIterator &other);

        // Main functions
        MyIterator<int>& begin();
        MyIterator<int>& end();
        
    };
}

#endif