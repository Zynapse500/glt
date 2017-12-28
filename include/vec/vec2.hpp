//
// Created by Christofer Nolander on 2017-12-27.
//

#pragma once

#include <cmath>

namespace glt {
    template <class T>
    struct Vec2 {
    public:

        T x, y;

        inline Vec2() = default;

        inline Vec2(const Vec2<T>& vec) :
                x(vec.x), y(vec.y)
        {}


        inline Vec2(T a, T b) :
                x(a), y(b)
        {}

        inline explicit Vec2(T a) :
                x(a), y(a)
        {}
    };


    // Operators


    // Addition
    template <class T>
    inline Vec2<T> operator+(const Vec2<T>& lhs, const Vec2<T>& rhs) {
        return {lhs.x + rhs.x, lhs.y + rhs.y};
    }

    template <class T>
    inline Vec2<T> operator+(const T& lhs, const Vec2<T>& rhs) {
        return {lhs + rhs.x, lhs + rhs.y};
    }

    template <class T>
    inline Vec2<T> operator+(const Vec2<T>& lhs, const T& rhs) {
        return {lhs.x + rhs, lhs.y + rhs};
    }


    // Subtraction
    template <class T>
    inline Vec2<T> operator-(const Vec2<T>& lhs, const Vec2<T>& rhs) {
        return {lhs.x - rhs.x, lhs.y - rhs.y};
    }

    template <class T>
    inline Vec2<T> operator-(const T& lhs, const Vec2<T>& rhs) {
        return {lhs - rhs.x, lhs - rhs.y};
    }

    template <class T>
    inline Vec2<T> operator-(const Vec2<T>& lhs, const T& rhs) {
        return {lhs.x - rhs, lhs.y - rhs};
    }


    // Multiplication
    template <class T>
    inline Vec2<T> operator*(const Vec2<T>& lhs, const Vec2<T>& rhs) {
        return {lhs.x * rhs.x, lhs.y * rhs.y};
    }

    template <class T>
    inline Vec2<T> operator*(const T& lhs, const Vec2<T>& rhs) {
        return {lhs * rhs.x, lhs * rhs.y};
    }

    template <class T>
    inline Vec2<T> operator*(const Vec2<T>& lhs, const T& rhs) {
        return {lhs.x * rhs, lhs.y * rhs};
    }


    // Division
    template <class T>
    inline Vec2<T> operator/(const Vec2<T>& lhs, const Vec2<T>& rhs) {
        return {lhs.x / rhs.x, lhs.y / rhs.y};
    }

    template <class T>
    inline Vec2<T> operator/(const T& lhs, const Vec2<T>& rhs) {
        return {lhs / rhs.x, lhs / rhs.y};
    }

    template <class T>
    inline Vec2<T> operator/(const Vec2<T>& lhs, const T& rhs) {
        return {lhs.x / rhs, lhs.y / rhs};
    }
}
