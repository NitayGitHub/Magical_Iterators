#ifndef MYITERATOR_H
#define MYITERATOR_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>

using namespace std;

namespace ariel
{
    template <typename T>
    class MyIterator
    {
        private:
            _List_const_iterator<T> _curr;
            _List_const_iterator<T> _end;

        public:
            // Constructors
            MyIterator(_List_const_iterator<T> curr, _List_const_iterator<T> end);
            MyIterator();
            ~MyIterator();

            // Operators

            // Main functions
            bool hasNext();
            T next();

            // Getters and setters
            _List_const_iterator<T> getCurr() { return _curr; }
            _List_const_iterator<T> getEnd() { return _end; }
            void setCurr(_List_const_iterator<T> curr) { _curr = curr; }
            void setEnd(_List_const_iterator<T> end) { _end = end; }

    };
}

#endif