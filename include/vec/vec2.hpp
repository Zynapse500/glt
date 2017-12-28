//
// Created by Christofer Nolander on 2017-12-27.
//

#pragma once

#include <cmath>

namespace glt {
    template <class T>
    struct vec2 {
    public:

        T x, y;

        inline vec2() = default;

        inline vec2(const vec2<T>& vec) :
                x(vec.x), y(vec.y)
        {}


        inline vec2(T a, T b) :
                x(a), y(b)
        {}

        inline explicit vec2(T a) :
                x(a), y(a)
        {}


        // Get value from index
        inline T& operator[](int index) {
            switch (index) {
                case 0: return x;
                case 1: return y;

                default: throw;
            }
        }

        inline const T& operator[](int index) const {
            switch (index) {
                case 0: return x;
                case 1: return y;

                default: throw;
            }
        }


        // Unary minus
        inline vec2<T> operator-() {
            return {-x, -y};
        }
    };


    // Operators


    // Addition
    template <class T>
    inline vec2<T> operator+(const vec2<T>& lhs, const vec2<T>& rhs) {
        return {lhs.x + rhs.x, lhs.y + rhs.y};
    }

    template <class T>
    inline vec2<T> operator+(const T& lhs, const vec2<T>& rhs) {
        return {lhs + rhs.x, lhs + rhs.y};
    }

    template <class T>
    inline vec2<T> operator+(const vec2<T>& lhs, const T& rhs) {
        return {lhs.x + rhs, lhs.y + rhs};
    }


    // Subtraction
    template <class T>
    inline vec2<T> operator-(const vec2<T>& lhs, const vec2<T>& rhs) {
        return {lhs.x - rhs.x, lhs.y - rhs.y};
    }

    template <class T>
    inline vec2<T> operator-(const T& lhs, const vec2<T>& rhs) {
        return {lhs - rhs.x, lhs - rhs.y};
    }

    template <class T>
    inline vec2<T> operator-(const vec2<T>& lhs, const T& rhs) {
        return {lhs.x - rhs, lhs.y - rhs};
    }


    // Multiplication
    template <class T>
    inline vec2<T> operator*(const vec2<T>& lhs, const vec2<T>& rhs) {
        return {lhs.x * rhs.x, lhs.y * rhs.y};
    }

    template <class T>
    inline vec2<T> operator*(const T& lhs, const vec2<T>& rhs) {
        return {lhs * rhs.x, lhs * rhs.y};
    }

    template <class T>
    inline vec2<T> operator*(const vec2<T>& lhs, const T& rhs) {
        return {lhs.x * rhs, lhs.y * rhs};
    }


    // Division
    template <class T>
    inline vec2<T> operator/(const vec2<T>& lhs, const vec2<T>& rhs) {
        return {lhs.x / rhs.x, lhs.y / rhs.y};
    }

    template <class T>
    inline vec2<T> operator/(const T& lhs, const vec2<T>& rhs) {
        return {lhs / rhs.x, lhs / rhs.y};
    }

    template <class T>
    inline vec2<T> operator/(const vec2<T>& lhs, const T& rhs) {
        return {lhs.x / rhs, lhs.y / rhs};
    }
}
