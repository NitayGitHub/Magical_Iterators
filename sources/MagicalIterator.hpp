#ifndef MAGICALITERATOR_H
#define MAGICALITERATOR_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace ariel
{
    enum IteratorType
    {
        ASCENDING,
        PRIME,
        CROSS
    };

    class MagicalIterator
    {
    protected:
        vector<int *> &List;
        IteratorType type;
        int **_curr;

    public:
        // Constructors
        MagicalIterator(vector<int *> &List, IteratorType type, int **curr = nullptr);
        MagicalIterator(const MagicalIterator &other);
        virtual ~MagicalIterator();

        // Operators
        MagicalIterator &operator=(const MagicalIterator &other);
        bool operator==(const MagicalIterator &other) const;
        bool operator!=(const MagicalIterator &other) const;
        bool operator<(const MagicalIterator &other) const;
        bool operator>(const MagicalIterator &other) const;
        int &operator*() const;
        MagicalIterator &operator++();

        // Main functions
        MagicalIterator begin();
        MagicalIterator end();

        // Getters and setters
        IteratorType getType() const;
        int **getCurr() const;
        void setCurr(int **curr);
    };
}

#endif