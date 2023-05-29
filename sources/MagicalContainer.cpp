#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
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
        vector<int>::iterator index = find(_container.begin(), _container.end(), element);
        _container.erase(index);
    }

    int MagicalContainer::size() const
    {
        return _container.size();
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
    vector<int> &MagicalContainer::getContainer() const
    {
        return (vector<int> &)_container;
    }
}