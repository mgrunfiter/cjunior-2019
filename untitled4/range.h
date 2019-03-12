#ifndef RANGE_H
#define RANGE_H

#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
std::vector<T> Range(std::vector<T> const &v, size_t top)
{
    return {v.begin(), next(v.begin(), std::min(top, v.size()))};
}

#endif // RANGE_H
