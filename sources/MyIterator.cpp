#include "MyIterator.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    template <typename T> MyIterator<T>::MyIterator(_List_const_iterator<T> curr, _List_const_iterator<T> end) : _curr(curr), _end(end) {}

    template <typename T> MyIterator<T>::~MyIterator() {}

    // Operators

    // Main functions

    template <typename T> bool MyIterator<T>::hasNext()
    {
        return _curr != _end;
    }

    template <typename T> T MyIterator<T>::next()
    {
        if (!hasNext())
        {
            throw out_of_range("Out of range");
        }
        T res = *_curr;
        _curr++;
        return res;
    }
}