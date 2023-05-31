#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    // Constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container) : 
    sideCrossList(container.getSideCrossList()), MagicalIterator(CROSS) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : 
    sideCrossList(other.sideCrossList), MagicalIterator(CROSS) {
        _curr = other._curr;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(vector<int*> &sideCrossList) :
    sideCrossList(sideCrossList), MagicalIterator(CROSS) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // Operators
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (this != &other)
        {
            sideCrossList = other.sideCrossList;
            _curr = other._curr;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const MagicalIterator &other) const
    {
        return _curr == other.getCurr();
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const MagicalIterator &other) const
    {
        return _curr != other.getCurr();
    }

    bool MagicalContainer::SideCrossIterator::operator<(const MagicalIterator &other) const
    {
        return _curr < other.getCurr();
    }

    bool MagicalContainer::SideCrossIterator::operator>(const MagicalIterator &other) const
    {
        return _curr > other.getCurr();
    }

    int& MagicalContainer::SideCrossIterator::operator*() const
    {
        return **_curr;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
    {
        _curr++;
        return *this;
    }

    // Main functions
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        MagicalContainer::SideCrossIterator ai = MagicalContainer::SideCrossIterator(sideCrossList);
        ai.setCurr(&sideCrossList[0]);
        return ai;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        MagicalContainer::SideCrossIterator ai = MagicalContainer::SideCrossIterator(sideCrossList);
        ai.setCurr(&sideCrossList.back() + 1);
        return ai;
    }

    // Getters and setters

    void MagicalContainer::SideCrossIterator::setCurr(int** curr)
    {
        _curr = curr;
    }

}