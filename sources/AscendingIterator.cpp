#include "AscendingIterator.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    AscendingIterator::AscendingIterator(MagicalContainer &container) : _magicalContainer(container)
    {
        list<int> ascendingList;
        copy(_magicalContainer.getContainer().begin(), _magicalContainer.getContainer().end(), ascendingList.begin());
        ascendingList.sort();
        _ascendingIterator = MyIterator<int>(ascendingList.begin(), ascendingList.end());
    }

    AscendingIterator::AscendingIterator(const AscendingIterator &other) : AscendingIterator(other._magicalContainer) {}

    AscendingIterator::~AscendingIterator() {}

    // Operators
    AscendingIterator &AscendingIterator::operator=(AscendingIterator &other)
    {
        if (this != &other)
        {
            _magicalContainer = other._magicalContainer;
            _ascendingIterator.setCurr(other._ascendingIterator.getCurr());
            _ascendingIterator.setEnd(other._ascendingIterator.getEnd());
        }
        return *this;
    }

    bool &AscendingIterator::operator==(AscendingIterator &other)
    {
        bool res = true;
        for(auto it = begin(), it2 = other.begin(); it != end() && it2 != other.end(); ++it, ++it2)
        {
            if(it != it2)
            {
                res = false;
                break;
            }
        }
        return res;
    }

    bool &AscendingIterator::operator!=(AscendingIterator &other)
    {
        bool res = false;
        for(auto it = begin(), it2 = other.begin(); it != end() && it2 != other.end(); ++it, ++it2)
        {
            if(it != it2)
            {
                res = true;
                break;
            }
        }
        return res;
    }

    // Main functions
    _List_const_iterator<int>& AscendingIterator::begin()
    {
        return _ascendingContainer;
    }

    _List_const_iterator<int>& AscendingIterator::end()
    {
        return _ascendingContainer;
    }

}