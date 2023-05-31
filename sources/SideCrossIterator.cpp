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
    MagicalIterator(container.getSideCrossList(), CROSS) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : 
    MagicalIterator(other.List, other.type, other._curr) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}
}