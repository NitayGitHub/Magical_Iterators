#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
namespace ariel
{
    // Main Functions
    void MagicalContainer::addElement(int element)
    {
        // add to container
        _container.push_back(element);

        // add to ascendingList
        ascendingList.push_back(element);
        sort(ascendingList.begin(), ascendingList.end());
    }

    void MagicalContainer::removeElement(int element)
    {
        vector<int>::iterator index = find(_container.begin(), _container.end(), element);
        vector<int>::iterator ascIndex = find(ascendingList.begin(), ascendingList.end(), element);
        _container.erase(index);
        ascendingList.erase(ascIndex);
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

    vector<int> &MagicalContainer::getAscendingList() const
    {
        return (vector<int> &)ascendingList;
    }
}