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
        vector<int *> temp;

        // add to container
        _container.push_back(element);

        // add to ascendingList
        temp = getAscendingOrder(_container);
        for (unsigned long i = 0; i < temp.size(); i++)
        {
            if (i + 1 == temp.size())
            {
                getAscendingList().push_back(temp[i]);
                break;
            }
            getAscendingList().at(i) = temp[i];
        }

        // add to primeList
        if (isPrime(element))
        {
            temp = getPrimeOrder(_container);
            for (unsigned long i = 0; i < temp.size(); i++)
            {
                if (i + 1 == temp.size())
                {
                    getPrimeList().push_back(temp[i]);
                    break;
                }
                getPrimeList().at(i) = temp[i];
            }
        }

        // add to sideCrossList
        temp = GetCrossOrder(_container);
        for (unsigned long i = 0; i < temp.size(); i++)
        {
            if (i + 1 == temp.size())
            {
                getSideCrossList().push_back(temp[i]);
                return;
            }
            getSideCrossList().at(i) = temp[i];
        }
    }

    void MagicalContainer::removeElement(int element)
    {
        // remove from container
        vector<int>::iterator index = find(_container.begin(), _container.end(), element);
        if (index == _container.end())
        {
            throw invalid_argument("Element not found");
        }
        _container.erase(index);

        // remove from primeList
        if (isPrime(element))
        {
            primeList.clear();
            for (auto it = _container.begin(); it != _container.end(); ++it)
            {
                if (isPrime(*it))
                {
                    primeList.push_back(&(*it));
                }
            }
        }

        // remove from ascendingList
        ascendingList.clear();
        for (auto it = _container.begin(); it != _container.end(); ++it)
        {
            ascendingList.push_back(&(*it));
        }
        sort(ascendingList.begin(), ascendingList.end(), [](int *a, int *b)
             { return *a < *b; });

        // remove from sideCrossList
        if (_container.size() == 0)
        {
            getSideCrossList().clear();
            return;
        }
        vector<int *> temp = GetCrossOrder(_container);
        for (unsigned long i = 0; i < temp.size(); i++)
        {
            if (*getSideCrossList().at(i) == *temp[i])
            {
                continue;
            }
            getSideCrossList().at(i) = temp[i];
        }
        getSideCrossList().pop_back();
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

    bool MagicalContainer::isPrime(int num) const
    {
        if (num <= 1)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    vector<int *> MagicalContainer::GetCrossOrder(vector<int> &arr)
    {
        unsigned long left = 0;               // Pointer starting from the beginning
        unsigned long right = arr.size() - 1; // Pointer starting from the end

        vector<int *> result;

        while (left <= right)
        {
            result.push_back(&arr[left++]); // Select an element from the start
            if (left <= right)
            {
                result.push_back(&arr[right--]); // Select an element from the end
            }
        }

        return result;
    }

    vector<int *> MagicalContainer::getAscendingOrder(vector<int> &arr)
    {
        vector<int *> result;
        for (auto it = arr.begin(); it != arr.end(); ++it)
        {
            result.push_back(&(*it));
        }
        sort(result.begin(), result.end(), [](int *a, int *b)
             { return *a < *b; });
        return result;
    }

    vector<int *> MagicalContainer::getPrimeOrder(vector<int> &arr)
    {
        vector<int *> result;
        for (auto it = arr.begin(); it != arr.end(); ++it)
        {
            if (isPrime(*it))
            {
                result.push_back(&(*it));
            }
        }
        return result;
    }

    // Getters
    vector<int> &MagicalContainer::getContainer() const
    {
        return (vector<int> &)_container;
    }

    vector<int *> &MagicalContainer::getAscendingList() const
    {
        return (vector<int *> &)ascendingList;
    }

    vector<int *> &MagicalContainer::getPrimeList() const
    {
        return (vector<int *> &)primeList;
    }

    vector<int *> &MagicalContainer::getSideCrossList() const
    {
        return (vector<int *> &)sideCrossList;
    }
}