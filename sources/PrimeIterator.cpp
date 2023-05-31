#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) : 
    primeList(container.getPrimeList()), MagicalIterator(PRIME) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : 
    primeList(other.primeList), MagicalIterator(PRIME) {
        _curr = other._curr;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(vector<int*> &primeList) : 
    primeList(primeList), MagicalIterator(PRIME) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // Operators

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (this != &other)
        {
            primeList = other.primeList;
            _curr = other._curr;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const MagicalIterator &other) const
    {
        return _curr == other.getCurr();
    }

    bool MagicalContainer::PrimeIterator::operator!=(const MagicalIterator &other) const
    {
        return _curr != other.getCurr();
    }

    bool MagicalContainer::PrimeIterator::operator<(const MagicalIterator &other) const
    {
        return _curr < other.getCurr();
    }

    bool MagicalContainer::PrimeIterator::operator>(const MagicalIterator &other) const
    {
        return _curr > other.getCurr();
    }

    int& MagicalContainer::PrimeIterator::operator*() const
    {
        return **_curr;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
    {
        _curr++;
        return *this;
    }

    // Main functions
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        MagicalContainer::PrimeIterator pi = MagicalContainer::PrimeIterator(primeList);
        pi.setCurr(&primeList[0]);
        return pi;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        MagicalContainer::PrimeIterator pi = MagicalContainer::PrimeIterator(primeList);
        pi.setCurr(&primeList[primeList.size()]);
        return pi;
    }

    // Getters and setters

    void MagicalContainer::PrimeIterator::setCurr(int** curr)
    {
        _curr = curr;
    }

}