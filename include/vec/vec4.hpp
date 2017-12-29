//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include "vec2.hpp"
#include "vec3.hpp"


namespace glt {
    template<class T>
    struct vec4 {
    public:

        union {
            struct {
                T x, y, z, w;
            };
            struct {
                T r, g, b, a;
            };
        };

        inline vec4() = default;


        template <class C>
        inline vec4(const vec4<C> &vec) : // NOLINT
                x(vec.x), y(vec.y), z(vec.z), w(vec.w)
        {}

        inline vec4(T x, T y, T z, T w) :
                x(x), y(y), z(z), w(w)
        {}

        inline explicit vec4(T a) :
                x(a), y(a), z(a), w(a)
        {}



        // Conversion between vector types

        // From vec2
        inline vec4(const vec2<T>& v, T z = T(), T w = T()) : // NOLINT
                x(v.x), y(v.y), z(z), w(w)
        {}

        inline vec4(T x, const vec2<T>& v, T w = T()) : // NOLINT
                x(x), y(v.x), z(v.y), w(w)
        {}

        inline vec4(T x, T y, const vec2<T>& v) : // NOLINT
                x(x), y(w), z(v.x), w(v.y)
        {}

        inline vec4(const vec2<T>& a, const vec2<T>& b) :
                x(a.x), y(a.y), z(b.x), w(b.y)
        {}


        // From vec3
        inline vec4(const vec3<T>& v, T w = T()) : // NOLINT
                x(v.x), y(v.y), z(v.z), w(w)
        {}

        inline vec4(T x, const vec3<T>& v) : // NOLINT
                x(x), y(v.x), z(v.y), w(v.z)
        {}



        // Convert to simpler types
        inline operator vec2<T>() { // NOLINT
            return {x, y};
        }

        inline operator vec3<T>() { // NOLINT
            return {x, y, z};
        }


        // Get value from index
        inline T& operator[](int index) {
            switch (index) {
                case 0: return x;
                case 1: return y;
                case 2: return z;
                case 3: return w;

                default: throw;
            }
        }

        inline const T& operator[](int index) const {
            switch (index) {
                case 0: return x;
                case 1: return y;
                case 2: return z;
                case 3: return w;

                default: throw;
            }
        }


        // Assignment
        inline void operator+=(const vec4<T>& other) {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            this->w += other.w;
        }

        inline void operator-=(const vec4<T>& other) {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
            this->w -= other.w;
        }

        inline void operator*=(const vec4<T>& other) {
            this->x *= other.x;
            this->y *= other.y;
            this->z *= other.z;
            this->w *= other.w;
        }

        inline void operator/=(const vec4<T>& other) {
            this->x /= other.x;
            this->y /= other.y;
            this->z /= other.z;
            this->w /= other.w;
        }


        // Unary minus
        inline vec4<T> operator-() {
            return {-x, -y, -z, -w};
        }
    };


    // Operators


    // Addition
    template<class T>
    inline vec4<T> operator+(const vec4<T> &lhs, const vec4<T> &rhs) {
        return {lhs.x + rhs.x, lhs.x + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
    }

    template<class T>
    inline vec4<T> operator+(const T &lhs, const vec4<T> &rhs) {
        return {lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w};
    }

    template<class T>
    inline vec4<T> operator+(const vec4<T> &lhs, const T &rhs) {
        return {lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs};
    }


    // Subtraction
    template<class T>
    inline vec4<T> operator-(const vec4<T> &lhs, const vec4<T> &rhs) {
        return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
    }

    template<class T>
    inline vec4<T> operator-(const T &lhs, const vec4<T> &rhs) {
        return {lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w};
    }

    template<class T>
    inline vec4<T> operator-(const vec4<T> &lhs, const T &rhs) {
        return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs};
    }


    // Multiplication
    template<class T>
    inline vec4<T> operator*(const vec4<T> &lhs, const vec4<T> &rhs) {
        return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
    }

    template<class T>
    inline vec4<T> operator*(const T &lhs, const vec4<T> &rhs) {
        return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w};
    }

    template<class T>
    inline vec4<T> operator*(const vec4<T> &lhs, const T &rhs) {
        return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs};
    }


    // Division
    template<class T>
    inline vec4<T> operator/(const vec4<T> &lhs, const vec4<T> &rhs) {
        return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
    }

    template<class T>
    inline vec4<T> operator/(const T &lhs, const vec4<T> &rhs) {
        return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w};
    }

    template<class T>
    inline vec4<T> operator/(const vec4<T> &lhs, const T &rhs) {
        return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs};
    }
}


