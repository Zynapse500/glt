//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include "tmat4.hpp"


namespace glt {

    // Translate matrix
    template <class T>
    tmat4<T> translate(const tmat4<T>& m, const vec3<T>& amount) {
        // Translation matrix
        tmat4<T> translation;

        translation[12] = amount.x;
        translation[13] = amount.y;
        translation[14] = amount.z;

        return translation * m;
    }


    // Scale matrix
    template <class T>
    tmat4<T> scale(const tmat4<T>& m, const vec3<T>& amount) {
        // Scale matrix
        tmat4<T> scale;

        scale[0]  = amount.x;
        scale[5]  = amount.y;
        scale[10] = amount.z;

        return scale * m;
    }


    // Rotate a matrix around an axis by an angle specified in radians
    template <class T>
    tmat4<T> rotate(const tmat4<T>& m, T angle, const vec3<T>& axis) {
        // Rotation matrix
        tmat4<T> rotation;

        T x = axis.x;
        T y = axis.y;
        T z = axis.z;

        T co = cos(angle);
        T si = sin(angle);

        T m_co = 1 - co;

        rotation[0] = co + x*x * m_co;   rotation[1] = x*y * m_co - z*si; rotation[2] = x*z * m_co + y*si;
        rotation[4] = x*y * m_co + z*si; rotation[5] = co + y*y * m_co;   rotation[6] = y*z * m_co - x*si;
        rotation[8] = x*z * m_co - y*si; rotation[9] = y*z * m_co + x*si; rotation[10] = co + z*z * m_co;

        return rotation * m;
    }
}
