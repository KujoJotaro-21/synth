#pragma once
#include <iostream>
#include <limits>

template <typename T>
T clamptotype(T val) {
    if (val < std::numeric_limits<T>::lowest()) {
        return std::numeric_limits<T>::lowest();
    }
    if (val > std::numeric_limits<T>::max()) {
        return std::numeric_limits<T>::max();
    }
    return val;
}

template <typename T>
T clamp(T a, T b, T val) {
    if (val > b) {
        //std::cout << "hitU!";
        return b;
    }
    if (val < a){
        //std::cout << "hitL!";
        return a;
    }
    //std::cout << val<<std::endl;
    return val;
}

template <typename T>
T sgn(T a) {
    return static_cast<T>(a > 0 ? 1 : (a == 0 ? 0 : -1));
}