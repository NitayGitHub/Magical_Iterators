#include "MagicalIterator.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
namespace ariel
{
    // constructors
    MagicalIterator::MagicalIterator(IteratorType type) : type(type) {}

    MagicalIterator::~MagicalIterator() {}

    // getters and setters

    IteratorType MagicalIterator::getType() const
    {
        return type;
    }

    int** MagicalIterator::getCurr() const
    {
        return _curr;
    }

}