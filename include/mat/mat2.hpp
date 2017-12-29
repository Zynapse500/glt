//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once


#include "../vec/vec2.hpp"

namespace glt {

// Convert a column and row to an index in a matrix
#define COL_ROW(col, row) ((col) + 2 * (row))

    template <class T>
    class mat2 {
    public:

        T data[2*2];


        // Create a new identity matrix
        mat2() :
                data{
                        T(1), T(0),
                        T(0), T(1),
                }
        {}

        // Create matrix filled with specific value
        explicit mat2(T value) :
                data{value} {}


        // Create matrix from raw data
        explicit mat2(T values[2*2]) {
            for (int i = 0; i < 2 * 2; ++i) {
                data[i] = values[i];
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
    mat2<T> operator*(const mat2<T>& a, const mat2<T>& b) {
        mat2<T> result{0};

        for (int col = 0; col < 2; ++col) {
            for (int row = 0; row < 2; ++row) {
                T& r = result[COL_ROW(col, row)];

                for (int k = 0; k < 2; ++k) {
                    r += a[COL_ROW(k, row)] * b[COL_ROW(col, k)];
                }
            }
        }

        return result;
    }

    // Matrix-vector multiplication
    template <class T>
    vec2<T> operator*(const mat2<T>& a, const vec2<T>& b) {
        vec2<T> result{0};

        for (int col = 0; col < 2; ++col) {
            T& r = result[col];

            for (int k = 0; k < 2; ++k) {
                r += a[COL_ROW(col, k)] * b[k];
            }
        }

        return result;
    }

#undef COL_ROW
}

