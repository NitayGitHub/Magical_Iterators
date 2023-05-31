#ifndef MAGICALITERATOR_H
#define MAGICALITERATOR_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace ariel
{
    enum IteratorType
    {
        ASCENDING,
        PRIME,
        CROSS
    };

    class MagicalIterator
    {
    protected:
        IteratorType type;
        int ** _curr;

    public:
        // Constructors
        MagicalIterator(IteratorType type);
        ~MagicalIterator();

        // Getters and setters
        IteratorType getType() const;
        int** getCurr() const;
        
    };
}

#endif