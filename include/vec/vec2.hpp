//
// Created by Christofer Nolander on 2017-12-27.
//

#pragma once

#include <cmath>

namespace glt {
    template <class T>
    struct vec2 {
    public:

        union {
            struct {
                T x, y;
            };
            struct {
                T r, g;
            };
        };

        inline vec2() = default;

        template <class C>
        inline explicit vec2(const vec2<C>& vec) :
                x(vec.x), y(vec.y)
        {}


        template <class C>
        inline vec2(C a, C b) :
                x(a), y(b)
        {}

        template <class C>
        inline explicit vec2(C a) :
                x(a), y(a)
        {}

        template <class C>
        inline operator vec2<C>() {
            return {static_cast<C>(x), static_cast<C>(y)};
        }

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


        // Assignment
        inline void operator+=(const vec2<T>& other) {
            this->x += other.x;
            this->y += other.y;
        }

        inline void operator-=(const vec2<T>& other) {
            this->x -= other.x;
            this->y -= other.y;
        }

        inline void operator*=(const vec2<T>& other) {
            this->x *= other.x;
            this->y *= other.y;
        }

        inline void operator/=(const vec2<T>& other) {
            this->x /= other.x;
            this->y /= other.y;
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
