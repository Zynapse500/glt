//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include "../vec/vec4.hpp"
#include <array>

namespace glt {

// Convert a column and row to an index in a matrix
#define COL_ROW(col, row) ((col) + 4 * (row))

    template <class T>
    class mat4 {
    public:

        T data[4*4];


        // Create a new identity matrix
        mat4() :
                data{
                             T(1), T(0), T(0), T(0),
                             T(0), T(1), T(0), T(0),
                             T(0), T(0), T(1), T(0),
                             T(0), T(0), T(0), T(1),
                    }
        {}

        // Create matrix filled with specific value
        explicit mat4(T value) :
                data{value} {}


        // Create matrix from raw data
        explicit mat4(std::array<T, 4*4> list) {
            for (int i = 0; i < 4 * 4; ++i) {
                data[i] = list[i];
            }
        }


        // Get value in specific index
        inline T& operator[](int index) {
            if (index >= 0 && index < 16)
                return data[index];
        }

        inline const T& operator[](int index) const {
            if (index >= 0 && index < 16)
                return data[index];
        }
    };


    // Operators

    // Matrix-matrix multiplication
    template <class T>
    mat4<T> operator*(const mat4<T>& a, const mat4<T>& b) {
        mat4<T> result{0};

        for (int col = 0; col < 4; ++col) {
            for (int row = 0; row < 4; ++row) {
                T& r = result[COL_ROW(col, row)];

                for (int k = 0; k < 4; ++k) {
                    r += a[COL_ROW(k, row)] * b[COL_ROW(col, k)];
                }
            }
        }

        return result;
    }

    // Matrix-vector multiplication
    template <class T>
    vec4<T> operator*(const mat4<T>& a, const vec4<T>& b) {
        vec4<T> result{0};

        for (int col = 0; col < 4; ++col) {
            T& r = result[col];

            for (int k = 0; k < 4; ++k) {
                r += a[COL_ROW(col, k)] * b[k];
            }
        }

        return result;
    }

    // Matrix-scalar multiplication
    template <class T>
    mat4<T> operator*(const T& s, const mat4<T>& a) {
        mat4<T> result{0};

        for (int col = 0; col < 4; ++col) {
            for (int row = 0; row < 4; ++row) {
                result[COL_ROW(col, row)] = s * a[COL_ROW(col, row)];
            }
        }

        return result;
    }

#undef COL_ROW
}

