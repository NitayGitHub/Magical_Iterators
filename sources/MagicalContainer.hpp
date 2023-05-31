#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "MagicalIterator.hpp"

using namespace std;

namespace ariel
{

    class MagicalContainer
    {
    private:
        vector<int> _container;
        vector<int*> ascendingList;
        vector<int*> primeList;
        vector<int*> sideCrossList;

    public:
        // Main functions
        void addElement(int element);
        void removeElement(int element);
        int size() const;

        // Aid functions
        bool isEmpty() const;
        bool isPrime(int num) const;
        vector<int*> GetCrossOrder(vector<int> &arr);
        vector<int*> getAscendingOrder(vector<int> &arr);
        vector<int*> getPrimeOrder(vector<int> &arr);
        string toString() const;

        // Getters
        vector<int> &getContainer() const;
        vector<int*> &getAscendingList() const;
        vector<int*> &getPrimeList() const;
        vector<int*> &getSideCrossList() const;

        // Iterators

        class AscendingIterator : public MagicalIterator
        {
        private:
            vector<int*> &ascendingList;

        public:
            // Constructors
            AscendingIterator(const MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(vector<int*> &ascendingList);
            ~AscendingIterator();

            // Operators
            AscendingIterator& operator=(const AscendingIterator &other);
            bool operator==(const MagicalIterator &other) const;
            bool operator!=(const MagicalIterator &other) const;
            bool operator<(const MagicalIterator &other) const;
            bool operator>(const MagicalIterator &other) const;
            int& operator*() const;
            AscendingIterator& operator++();

            // Main functions
            AscendingIterator begin();
            AscendingIterator end();

            // Getters and setters
            void setCurr(int** curr);
        };

        class PrimeIterator : public MagicalIterator
        {
        private:
            vector<int*> &primeList;

        public:
            // Constructors
            PrimeIterator(const MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator(vector<int*> &primeList);
            ~PrimeIterator();

            // Operators
            PrimeIterator& operator=(const PrimeIterator &other);
            bool operator==(const MagicalIterator &other) const;
            bool operator!=(const MagicalIterator &other) const;
            bool operator<(const MagicalIterator &other) const;
            bool operator>(const MagicalIterator &other) const;
            int& operator*() const;
            PrimeIterator& operator++();

            // Main functions
            PrimeIterator begin();
            PrimeIterator end();

            // Getters and setters
            void setCurr(int** curr);
        };

        class SideCrossIterator : public MagicalIterator
        {
        private:
            vector<int*> &sideCrossList;

        public:
            // Constructors
            SideCrossIterator(const MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(vector<int*> &sideCrossList);
            ~SideCrossIterator();

            // Operators
            SideCrossIterator& operator=(const SideCrossIterator &other);
            bool operator==(const MagicalIterator &other) const;
            bool operator!=(const MagicalIterator &other) const;
            bool operator<(const MagicalIterator &other) const;
            bool operator>(const MagicalIterator &other) const;
            int& operator*() const;
            SideCrossIterator& operator++();

            // Main functions
            SideCrossIterator begin();
            SideCrossIterator end();

            // Getters and setters
            void setCurr(int** curr);
        };
    };
}

#endif