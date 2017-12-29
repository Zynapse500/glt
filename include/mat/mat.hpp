//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include "mat4.hpp"
#include "mat3.hpp"
#include "mat2.hpp"

#include "mat_core.hpp"
#include "mat_projection.hpp"

namespace glt {

    // Define common matrix types
    typedef mat4<float> mat4f;
    typedef mat4<double> mat4d;



    // Define equality operators
    template <class T>
    bool operator==(const glt::mat4<T>& a, const glt::mat4<T>& b) {
        for (int i = 0; i < 4 * 4; ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }

    template <class T>
    bool operator==(const glt::mat3<T>& a, const glt::mat3<T>& b) {
        for (int i = 0; i < 3 * 3; ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }

    template <class T>
    bool operator==(const glt::mat2<T>& a, const glt::mat2<T>& b) {
        for (int i = 0; i < 2 * 2; ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }



    // Define inequality operators
    template <class T>
    bool operator==(const glt::mat4<T>& a, const glt::mat4<T>& b) {
        for (int i = 0; i < 4 * 4; ++i) {
            if (a[i] == b[i]) {
                return false;
            }
        }

        return true;
    }

    template <class T>
    bool operator==(const glt::mat3<T>& a, const glt::mat3<T>& b) {
        for (int i = 0; i < 3 * 3; ++i) {
            if (a[i] == b[i]) {
                return false;
            }
        }

        return true;
    }

    template <class T>
    bool operator==(const glt::mat2<T>& a, const glt::mat2<T>& b) {
        for (int i = 0; i < 2 * 2; ++i) {
            if (a[i] == b[i]) {
                return false;
            }
        }

        return true;
    }
}
