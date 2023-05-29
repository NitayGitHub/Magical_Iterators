#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : primeList(container.getPrimeList()) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // Main functions
    MyIterator<int> MagicalContainer::PrimeIterator::begin()
    {
        return MyIterator<int>(&primeList[0], PRIME);
    }

    MyIterator<int> MagicalContainer::PrimeIterator::end()
    {
        return MyIterator<int>(&primeList.back() + 1, PRIME);
    }

}