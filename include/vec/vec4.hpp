//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include "vec2.hpp"
#include "vec3.hpp"


namespace glt {
    template<class T>
    struct Vec4 {
    public:

        T x, y, z, w;

        inline Vec4() = default;

        inline Vec4(const Vec4<T> &vec) :
                x(vec.x), y(vec.y), z(vec.z), w(vec.w)
        {}

        inline Vec4(T x, T y, T z, T w) :
                x(x), y(y), z(z), w(w)
        {}

        inline explicit Vec4(T a) :
                x(a), y(a), z(a), w(a)
        {}



        // Conversion between vector types

        // From Vec2
        inline Vec4(const Vec2<T>& v, T z = T(), T w = T()) : // NOLINT
                x(v.x), y(v.y), z(z), w(w)
        {}

        inline Vec4(T x, const Vec2<T>& v, T w = T()) : // NOLINT
                x(x), y(v.x), z(v.y), w(w)
        {}

        inline Vec4(T x, T y, const Vec2<T>& v) : // NOLINT
                x(x), y(w), z(v.x), w(v.y)
        {}

        inline Vec4(const Vec2<T>& a, const Vec2<T>& b) :
                x(a.x), y(a.y), z(b.x), w(b.y)
        {}


        // From Vec3
        inline Vec4(const Vec3<T>& v, T w = T()) : // NOLINT
                x(v.x), y(v.y), z(v.z), w(w)
        {}

        inline Vec4(T x, const Vec3<T>& v) : // NOLINT
                x(x), y(v.x), z(v.y), w(v.z)
        {}



        // Convert to simpler types
        inline operator Vec2<T>() { // NOLINT
            return {x, y};
        }

        inline operator Vec3<T>() { // NOLINT
            return {x, y, z};
        }
    };


    // Operators


    // Addition
    template<class T>
    inline Vec4<T> operator+(const Vec4<T> &lhs, const Vec4<T> &rhs) {
        return {lhs.x + rhs.x, lhs.x + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
    }

    template<class T>
    inline Vec4<T> operator+(const T &lhs, const Vec4<T> &rhs) {
        return {lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w};
    }

    template<class T>
    inline Vec4<T> operator+(const Vec4<T> &lhs, const T &rhs) {
        return {lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs};
    }


    // Subtraction
    template<class T>
    inline Vec4<T> operator-(const Vec4<T> &lhs, const Vec4<T> &rhs) {
        return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
    }

    template<class T>
    inline Vec4<T> operator-(const T &lhs, const Vec4<T> &rhs) {
        return {lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w};
    }

    template<class T>
    inline Vec4<T> operator-(const Vec4<T> &lhs, const T &rhs) {
        return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs};
    }


    // Multiplication
    template<class T>
    inline Vec4<T> operator*(const Vec4<T> &lhs, const Vec4<T> &rhs) {
        return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
    }

    template<class T>
    inline Vec4<T> operator*(const T &lhs, const Vec4<T> &rhs) {
        return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w};
    }

    template<class T>
    inline Vec4<T> operator*(const Vec4<T> &lhs, const T &rhs) {
        return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs};
    }


    // Division
    template<class T>
    inline Vec4<T> operator/(const Vec4<T> &lhs, const Vec4<T> &rhs) {
        return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
    }

    template<class T>
    inline Vec4<T> operator/(const T &lhs, const Vec4<T> &rhs) {
        return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w};
    }

    template<class T>
    inline Vec4<T> operator/(const Vec4<T> &lhs, const T &rhs) {
        return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs};
    }
}


