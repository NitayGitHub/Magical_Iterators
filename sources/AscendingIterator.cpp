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
    MagicalIterator(container.getAscendingList(), ASCENDING) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : 
    MagicalIterator(other.List, other.type, other._curr) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

}