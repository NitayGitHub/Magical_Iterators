#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : ascendingList(container.getAscendingList()) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Main functions
    MyIterator<int> MagicalContainer::AscendingIterator::begin()
    {
        return MyIterator<int>(&ascendingList[0], ASC);
    }

    MyIterator<int> MagicalContainer::AscendingIterator::end()
    {
        return MyIterator<int>(&ascendingList.back() + 1, ASC);
    }

}