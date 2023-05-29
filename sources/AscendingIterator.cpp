#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

namespace ariel
{
    // Constructors
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : _magicalContainer(container)
    {
        list<int> ascendingList;
        copy(_magicalContainer.getContainer().begin(), _magicalContainer.getContainer().end(), ascendingList.begin());
        ascendingList.sort();
        _ascendingIterator = MyIterator<int>(ascendingList.begin(), ascendingList.end());
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : AscendingIterator(other._magicalContainer) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Main functions
    MyIterator<int>& MagicalContainer::AscendingIterator::begin()
    {
        return _ascendingIterator;
    }

    MyIterator<int>& MagicalContainer::AscendingIterator::end()
    {
        return _ascendingIterator;
    }

}