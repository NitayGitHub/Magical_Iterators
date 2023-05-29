#ifndef MYITERATOR_H
#define MYITERATOR_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>

using namespace std;

namespace ariel
{
    enum iteratorType
    {
        ASC,
        PRIME,
        CROSS
    };
    
    template <typename T>
    class MyIterator
    {
        private:
            T* _curr;
            iteratorType _type;

        public:
            // Constructors
            MyIterator(T* first, iteratorType type);
            MyIterator();
            ~MyIterator();

            // Operators
            MyIterator<T>& operator=(const MyIterator<T> &other);
            bool operator==(const MyIterator<T> &other) const;
            bool operator!=(const MyIterator<T> &other) const;
            bool operator<(const MyIterator<T> &other) const;
            bool operator>(const MyIterator<T> &other) const;
            T operator*() const;
            MyIterator<T>& operator++();

            // Getters and setters
            T* getCurr() const;
            iteratorType getType() const;
            void setCurr(T* curr);

    };
}

#endif