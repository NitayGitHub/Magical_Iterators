#include "MagicalIterator.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    MagicalIterator::MagicalIterator(vector<int *> &List, IteratorType type, int **curr) : _curr(curr), type(type), List(List) {}

    MagicalIterator::MagicalIterator(const MagicalIterator &other) : _curr(other._curr), type(other.type), List(other.List) {}

    MagicalIterator::~MagicalIterator() {}

    // Operators

    MagicalIterator &MagicalIterator::operator=(const MagicalIterator &other)
    {
        if (this != &other)
        {
            _curr = other._curr;
            type = other.type;
            List = other.List;
        }
        return *this;
    }

    bool MagicalIterator::operator==(const MagicalIterator &other) const
    {
        if (getType() != other.getType())
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return _curr == other.getCurr();
    }

    bool MagicalIterator::operator!=(const MagicalIterator &other) const
    {
        if (getType() != other.getType())
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return _curr != other.getCurr();
    }

    bool MagicalIterator::operator<(const MagicalIterator &other) const
    {
        if (getType() != other.getType())
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return _curr < other.getCurr();
    }

    bool MagicalIterator::operator>(const MagicalIterator &other) const
    {
        if (getType() != other.getType())
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return _curr > other.getCurr();
    }

    int &MagicalIterator::operator*() const
    {
        return **_curr;
    }

    MagicalIterator &MagicalIterator::operator++()
    {
        _curr++;
        return *this;
    }

    // Main functions

    MagicalIterator MagicalIterator::begin()
    {
        MagicalIterator mi = MagicalIterator(*this);
        mi.setCurr(&List[0]);
        return mi;
    }

    MagicalIterator MagicalIterator::end()
    {
        MagicalIterator mi = MagicalIterator(*this);
        mi.setCurr(&List.back() + 1);
        return mi;
    }

    // Getters and setters
    IteratorType MagicalIterator::getType() const
    {
        return type;
    }

    int **MagicalIterator::getCurr() const
    {
        return _curr;
    }

    void MagicalIterator::setCurr(int **curr)
    {
        _curr = curr;
    }

}