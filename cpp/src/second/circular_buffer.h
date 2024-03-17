#pragma once

#ifndef CIRCULAR_mbuffer_H_
#define CIRCULAR_mbuffer_H_

#include <vector>

const unsigned int SIZE = 10;

// Класс Circularmbuffer0 на основе статической структуры данных

template <class T>
class CircularBuffer0
{
public:
    CircularBuffer0():
    msize(SIZE),
    mstart(0),
    mend(0)
    {}

    void push(const T value)
    {
        mbuffer[mend] = value;
        mend = (mend + 1) % msize;
        if (mend == mstart)
        {
            mstart = (mstart + 1) % msize;
        }
    }
    
    T pop()
    {
        if (mstart == mend)
        {
            std::cout << "Buffer is empty!" << std::endl;
            return -1;
        }
        int value = mbuffer[mstart];
        mstart = (mstart + 1) % msize;
        return value;
    }

    int size()
    {
        return msize;
    }

    bool isEmpty()
    {
        return mstart == mend;
    }

    bool isFull()
    {
        return (mend + 1) % msize == mstart;
    }
private:
    T mbuffer[SIZE];
    unsigned int msize;
    unsigned int mstart;
    unsigned int mend;
};

// Класс Circularmbuffer1 на основе динамической структуры данных

template <class T>
class CircularBuffer1
{
public:
    CircularBuffer1(const unsigned int size):
    mbuffer(size),
    msize(mbuffer.size()),
    mstart(0),
    mend(0)
    {}

    void push(const T value)
    {
        mbuffer[mend] = value;
        mend = (mend + 1) % msize;
        if (mend == mstart)
        {
            mstart = (mstart + 1) % msize;
        }
    }

    T pop()
    {
        if (mstart == mend)
        {
            std::cout << "Buffer is empty!" << std::endl;
            return -1;
        }
        int value = mbuffer[mstart];
        mstart = (mstart + 1) % msize;
        return value;
    }

    int size()
    {
        return msize;
    }

    bool isEmpty()
    {
        return mstart == mend;
    }

    bool isFull()
    {
        return (mend + 1) % msize == mstart;
    }
private:
    std::vector<T> mbuffer;
    unsigned int msize;
    unsigned int mstart;
    unsigned int mend;
};

#endif