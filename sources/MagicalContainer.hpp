#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "MyIterator.hpp"
#include "MyIterator.cpp"

using namespace std;

namespace ariel
{

    class MagicalContainer
    {
    private:
        vector<int> _container;
        vector<int> ascendingList;
        vector<int> primeList;
        vector<int> sideCrossList;

    public:
        // Main functions
        void addElement(int element);
        void removeElement(int element);
        int size() const;

        // Aid functions
        bool isEmpty() const;
        bool isPrime(int num) const;
        vector<int> GetCrossOrderArray(vector<int> &arr);
        string toString() const;

        // Getters
        vector<int> &getContainer() const;
        vector<int> &getAscendingList() const;
        vector<int> &getPrimeList() const;
        vector<int> &getSideCrossList() const;

        // Iterators

        class AscendingIterator
        {
        private:
            vector<int> &ascendingList;

        public:
            // Constructors
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            // Main functions
            MyIterator<int> begin();
            MyIterator<int> end();
        };

        class PrimeIterator
        {
        private:
            vector<int> &primeList;

        public:
            // Constructors
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();

            // Main functions
            MyIterator<int> begin();
            MyIterator<int> end();
        };

        class SideCrossIterator
        {
        private:
            vector<int> &sideCrossList;

        public:
            // Constructors
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();

            // Main functions
            MyIterator<int> begin();
            MyIterator<int> end();
        };
    };
}

#endif