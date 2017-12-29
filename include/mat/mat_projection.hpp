//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once


#include "mat4.hpp"

#include "mat_core.hpp"

namespace glt {

    // Create an orthographic projection matrix
    // Maps the ranges [left, right], [bottom, top] and [near, far] into [-1, 1]
    template <class T>
    mat4<T> orthographic(T left, T right, T bottom, T top, T near, T far) {
        // The projection matrix
        mat4<T> projection{};

        vec3<T> translation = {
                -(right + left)/(right - left),
                -(top + bottom)/(top - bottom),
                -(far + near)/(far - near)
        };

        vec3<T> scaling = {
                T(2) / (right - left),
                T(2) / (top - bottom),
               -T(2) / (far - near),
        };

        projection[0] = scaling.x;
        projection[5] = scaling.y;
        projection[10] = scaling.z;

        projection[12] = translation.x;
        projection[13] = translation.y;
        projection[14] = translation.z;

        return projection;
    }

    template <class T>
    mat4<T> orthographic(T left, T right, T bottom, T top) {
        return orthographic(left, right, bottom, top, T(-1), T(1));
    }


    // Create a perspective projection matrix
    template <class T>
    mat4<T> projection(T fov, T aspect, T near, T far);
}
