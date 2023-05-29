#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors and destructors
    MagicalContainer::MagicalContainer() : _container() {}

    // Main Functions
    void MagicalContainer::addElement(int element)
    {
        _container.push_back(element);
    }

    void MagicalContainer::removeElement(int element)
    {
        _container.remove(element);
    }

    int MagicalContainer::size() const
    {
        return _container.size();
    }

    // Operators

    bool MagicalContainer::operator==(const MagicalContainer &other) const
    {
        return _container == other._container;
    }

    // Aid Functions

    bool MagicalContainer::isEmpty() const
    {
        return _container.empty();
    }

    string MagicalContainer::toString() const
    {
        string str = "";
        for (auto it = _container.begin(); it != _container.end(); ++it)
        {
            str += to_string(*it) + " ";
        }
        return str;
    }

    // Getters
    list<int> &MagicalContainer::getContainer() const
    {
        return (list<int> &)_container;
    }
}