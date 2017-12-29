//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include "../vec/vec3.hpp"
#include <array>

namespace glt {

// Convert a column and row to an index in a matrix
#define COL_ROW(col, row) ((col) + 3 * (row))

    template <class T>
    class mat3 {
    public:

        T data[3*3];


        // Create a new identity matrix
        mat3() :
                data{
                        T(1), T(0), T(0),
                        T(0), T(1), T(0),
                        T(0), T(0), T(1),
                }
        {}

        // Create matrix filled with specific value
        explicit mat3(T value) :
                data{value} {}


        // Create matrix from raw data
        explicit mat3(std::array<T, 3*3> list) {
            for (int i = 0; i < 3 * 3; ++i) {
                data[i] = list[i];
            }
        }


        // Get value in specific index
        inline T& operator[](int index) {
            if (index >= 0 && index < 3*3)
                return data[index];
        }

        inline const T& operator[](int index) const {
            if (index >= 0 && index < 3*3)
                return data[index];
        }
    };


    // Operators

    // Matrix-matrix multiplication
    template <class T>
    mat3<T> operator*(const mat3<T>& a, const mat3<T>& b) {
        mat3<T> result{0};

        for (int col = 0; col < 3; ++col) {
            for (int row = 0; row < 3; ++row) {
                T& r = result[COL_ROW(col, row)];

                for (int k = 0; k < 3; ++k) {
                    r += a[COL_ROW(k, row)] * b[COL_ROW(col, k)];
                }
            }
        }

        return result;
    }

    // Matrix-vector multiplication
    template <class T>
    vec3<T> operator*(const mat3<T>& a, const vec3<T>& b) {
        vec3<T> result{0};

        for (int col = 0; col < 3; ++col) {
            T& r = result[col];

            for (int k = 0; k < 3; ++k) {
                r += a[COL_ROW(col, k)] * b[k];
            }
        }

        return result;
    }

#undef COL_ROW
}

