//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include "vec2.hpp"


namespace glt {
    template<class T>
    struct vec3 {
    public:

        union {
            struct {
                T x, y, z;
            };
            struct {
                T r, g, b;
            };
        };

        inline vec3() = default;

        template <class C>
        inline vec3(const vec3<C> &vec) : // NOLINT
                x(vec.x), y(vec.y), z(vec.z)
        {}

        inline vec3(T x, T y, T z) :
                x(x), y(y), z(z)
        {}

        inline explicit vec3(T a) :
                x(a), y(a), z(a)
        {}



        // Conversion between vector types

        inline explicit vec3(const vec2<T>& v, T z = T()) :
                x(v.x), y(v.y), z(z)
        {}

        inline explicit vec3(T x, const vec2<T>& v) :
                x(x), y(v.x), z(v.y)
        {}


        inline operator vec2<T>() {
            return {x, y};
        }


        // Get value from index
        inline T& operator[](int index) {
            switch (index) {
                case 0: return x;
                case 1: return y;
                case 2: return z;

                default: throw;
            }
        }

        inline const T& operator[](int index) const {
            switch (index) {
                case 0: return x;
                case 1: return y;
                case 2: return z;

                default: throw;
            }
        }


        // Assignment
        inline void operator+=(const vec3<T>& other) {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
        }

        inline void operator-=(const vec3<T>& other) {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
        }

        inline void operator*=(const vec3<T>& other) {
            this->x *= other.x;
            this->y *= other.y;
            this->z *= other.z;
        }

        inline void operator/=(const vec3<T>& other) {
            this->x /= other.x;
            this->y /= other.y;
            this->z /= other.z;
        }


        // Unary minus
        inline vec3<T> operator-() {
            return {-x, -y, -z};
        }
    };


    // Operators


    // Addition
    template<class T>
    inline vec3<T> operator+(const vec3<T> &lhs, const vec3<T> &rhs) {
        return {lhs.x + rhs.x, lhs.x + rhs.y, lhs.z + rhs.z};
    }

    template<class T>
    inline vec3<T> operator+(const T &lhs, const vec3<T> &rhs) {
        return {lhs + rhs.x, lhs + rhs.y, lhs + rhs.z};
    }

    template<class T>
    inline vec3<T> operator+(const vec3<T> &lhs, const T &rhs) {
        return {lhs.x + rhs, lhs.y + rhs, lhs.z + rhs};
    }


    // Subtraction
    template<class T>
    inline vec3<T> operator-(const vec3<T> &lhs, const vec3<T> &rhs) {
        return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
    }

    template<class T>
    inline vec3<T> operator-(const T &lhs, const vec3<T> &rhs) {
        return {lhs - rhs.x, lhs - rhs.y, lhs - rhs.z};
    }

    template<class T>
    inline vec3<T> operator-(const vec3<T> &lhs, const T &rhs) {
        return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs};
    }


    // Multiplication
    template<class T>
    inline vec3<T> operator*(const vec3<T> &lhs, const vec3<T> &rhs) {
        return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
    }

    template<class T>
    inline vec3<T> operator*(const T &lhs, const vec3<T> &rhs) {
        return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
    }

    template<class T>
    inline vec3<T> operator*(const vec3<T> &lhs, const T &rhs) {
        return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
    }


    // Division
    template<class T>
    inline vec3<T> operator/(const vec3<T> &lhs, const vec3<T> &rhs) {
        return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
    }

    template<class T>
    inline vec3<T> operator/(const T &lhs, const vec3<T> &rhs) {
        return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z};
    }

    template<class T>
    inline vec3<T> operator/(const vec3<T> &lhs, const T &rhs) {
        return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
    }
}
