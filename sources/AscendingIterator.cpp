#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    // Constructors
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container) : 
    ascendingList(container.getAscendingList()), MagicalIterator(ASCENDING) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : 
    ascendingList(other.ascendingList), MagicalIterator(ASCENDING) {
        _curr = other._curr;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(vector<int*> &ascendingList) :
    ascendingList(ascendingList), MagicalIterator(ASCENDING) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Operators
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (this != &other)
        {
            ascendingList = other.ascendingList;
            _curr = other._curr;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const MagicalIterator &other) const
    {
        if(getType() != other.getType())
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return _curr == other.getCurr();
    }

    bool MagicalContainer::AscendingIterator::operator!=(const MagicalIterator &other) const
    {
        if(getType() != other.getType())
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return _curr != other.getCurr();
    }

    bool MagicalContainer::AscendingIterator::operator<(const MagicalIterator &other) const
    {
        if(getType() != other.getType())
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return _curr < other.getCurr();
    }

    bool MagicalContainer::AscendingIterator::operator>(const MagicalIterator &other) const
    {
        if(getType() != other.getType())
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return _curr > other.getCurr();
    }

    int& MagicalContainer::AscendingIterator::operator*() const
    {
        return **_curr;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
    {
        _curr++;
        return *this;
    }

    // Main functions
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        MagicalContainer::AscendingIterator ai = MagicalContainer::AscendingIterator(ascendingList);
        ai.setCurr(&ascendingList[0]);
        return ai;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        MagicalContainer::AscendingIterator ai = MagicalContainer::AscendingIterator(ascendingList);
        ai.setCurr(&ascendingList.back() + 1);
        return ai;
    }

    // Getters and setters
    void MagicalContainer::AscendingIterator::setCurr(int** curr)
    {
        _curr = curr;
    }

}