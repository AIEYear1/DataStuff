#pragma once

template <typename T>
class tVector
{
    const static size_t GROWTH_FACTOR = 2;

    T *arr;
    size_t arrSize;
    size_t arrCapacity;

public:
    tVector();

    tVector(const tVector &other);
    tVector &operator=(const tVector &rhs);
    ~tVector();

    void push_back(const T &value);

    T &at(size_t index);

    class iterator
    {
        tVector *vector;
        size_t cur;

    public:
        iterator();
        iterator(tVector *vec, size_t start);

        bool operator ==(iterator rhs);
        bool operator !=(iterator rhs);

        //T &operator *();

        T &operator++();
        T operator++(int);
    };

    iterator begin();
    iterator end();
};