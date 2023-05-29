#include "MyIterator.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    template <typename T>
    MyIterator<T>::MyIterator(T *first, iteratorType type) : _curr(first), _type(type) {}

    template <typename T>
    MyIterator<T>::MyIterator() : _curr(nullptr) {}

    template <typename T>
    MyIterator<T>::~MyIterator() {}

    // Operators
    template <typename T>
    MyIterator<T> &MyIterator<T>::operator=(const MyIterator<T> &other)
    {
        if(other.getType() != _type)
        {
            throw std::invalid_argument("Cannot assign iterator of different type");
        }
        if (this != &other)
        {
            setCurr(other.getCurr());
        }
        return *this;
    }

    template <typename T>
    bool MyIterator<T>::operator==(const MyIterator<T> &other) const
    {
        if(other.getType() != _type)
        {
            throw std::invalid_argument("Cannot compare iterator of different type");
        }
        return _curr == other.getCurr();
    }

    template <typename T>
    bool MyIterator<T>::operator!=(const MyIterator<T> &other) const
    {
        if(other.getType() != _type)
        {
            throw std::invalid_argument("Cannot compare iterator of different type");
        }
        return _curr != other.getCurr();
    }

    template <typename T>
    bool MyIterator<T>::operator<(const MyIterator<T> &other) const
    {
        if(other.getType() != _type)
        {
            throw std::invalid_argument("Cannot compare iterator of different type");
        }
        return _curr < other.getCurr();
    }

    template <typename T>
    bool MyIterator<T>::operator>(const MyIterator<T> &other) const
    {
        if(other.getType() != _type)
        {
            throw std::invalid_argument("Cannot compare iterator of different type");
        }
        return _curr > other.getCurr();
    }

    template <typename T>
    T MyIterator<T>::operator*() const
    {
        return *_curr;
    }

    template <typename T>
    MyIterator<T> &MyIterator<T>::operator++()
    {
        _curr++;
        return *this;
    }

    // Getters and setters
    template <typename T>
    T* MyIterator<T>::getCurr() const
    {
        return _curr;
    }

    template <typename T>
    iteratorType MyIterator<T>::getType() const
    {
        return _type;
    }

    template <typename T>
    void MyIterator<T>::setCurr(T *curr)
    {
        _curr = curr;
    }

}