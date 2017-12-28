//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once


#include "vec2.hpp"


namespace glt {
    template<class T>
    struct Vec3 {
    public:

        T x, y, z;

        inline Vec3() = default;

        inline Vec3(const Vec3<T> &vec) :
                x(vec.x), y(vec.y), z(vec.z)
        {}

        inline Vec3(T x, T y, T z) :
                x(x), y(y), z(z)
        {}

        inline explicit Vec3(T a) :
                x(a), y(a), z(a)
        {}



        // Conversion between vector types

        inline Vec3(const Vec2<T>& v, T z = T()) : // NOLINT
                x(v.x), y(v.y), z(z)
        {}

        inline Vec3(T x, const Vec2<T>& v) : // NOLINT
                x(x), y(v.x), z(v.y)
        {}


        inline operator Vec2<T>() {
            return {x, y};
        }
    };


    // Operators


    // Addition
    template<class T>
    inline Vec3<T> operator+(const Vec3<T> &lhs, const Vec3<T> &rhs) {
        return {lhs.x + rhs.x, lhs.x + rhs.y, lhs.z + rhs.z};
    }

    template<class T>
    inline Vec3<T> operator+(const T &lhs, const Vec3<T> &rhs) {
        return {lhs + rhs.x, lhs + rhs.y, lhs + rhs.z};
    }

    template<class T>
    inline Vec3<T> operator+(const Vec3<T> &lhs, const T &rhs) {
        return {lhs.x + rhs, lhs.y + rhs, lhs.z + rhs};
    }


    // Subtraction
    template<class T>
    inline Vec3<T> operator-(const Vec3<T> &lhs, const Vec3<T> &rhs) {
        return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
    }

    template<class T>
    inline Vec3<T> operator-(const T &lhs, const Vec3<T> &rhs) {
        return {lhs - rhs.x, lhs - rhs.y, lhs - rhs.z};
    }

    template<class T>
    inline Vec3<T> operator-(const Vec3<T> &lhs, const T &rhs) {
        return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs};
    }


    // Multiplication
    template<class T>
    inline Vec3<T> operator*(const Vec3<T> &lhs, const Vec3<T> &rhs) {
        return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
    }

    template<class T>
    inline Vec3<T> operator*(const T &lhs, const Vec3<T> &rhs) {
        return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
    }

    template<class T>
    inline Vec3<T> operator*(const Vec3<T> &lhs, const T &rhs) {
        return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
    }


    // Division
    template<class T>
    inline Vec3<T> operator/(const Vec3<T> &lhs, const Vec3<T> &rhs) {
        return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
    }

    template<class T>
    inline Vec3<T> operator/(const T &lhs, const Vec3<T> &rhs) {
        return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z};
    }

    template<class T>
    inline Vec3<T> operator/(const Vec3<T> &lhs, const T &rhs) {
        return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
    }
}
