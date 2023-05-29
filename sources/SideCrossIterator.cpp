#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : sideCrossList(container.getSideCrossList()) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // Main functions
    MyIterator<int> MagicalContainer::SideCrossIterator::begin()
    {
        return MyIterator<int>(&sideCrossList[0], CROSS);
    }

    MyIterator<int> MagicalContainer::SideCrossIterator::end()
    {
        return MyIterator<int>(&sideCrossList.back() + 1, CROSS);
    }

}