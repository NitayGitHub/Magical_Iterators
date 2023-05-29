#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    // Constructors
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : _magicalContainer(container)
    {
        for (auto it = container.getContainer().begin(); it != container.getContainer().end(); ++it)
        {
            ascendingList.push_back(*it);
        }
        sort(ascendingList.begin(), ascendingList.end());
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : AscendingIterator(other._magicalContainer) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Main functions
    int *MagicalContainer::AscendingIterator::begin()
    {
        return &ascendingList.front();
    }

    int *MagicalContainer::AscendingIterator::end()
    {
        return &ascendingList.back() + 1;
    }

}