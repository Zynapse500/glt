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


    // Create a look at orientation matrix
    // From center, orient vector to point at target
    template <class T>
    tmat4<T> lookAt(vec3<T> center, vec3<T> target, vec3<T> up) {

        // The new directions of the axes
        vec3<T> z = normalize(center - target);
        vec3<T> x = normalize(cross(up, z));
        vec3<T> y = cross(z, x);


        // The orientation matrix
        tmat4<T> orientation;

        orientation[0] = x.x;
        orientation[1] = y.x;
        orientation[2] = z.x;

        orientation[4] = x.y;
        orientation[5] = y.y;
        orientation[6] = z.y;

        orientation[8]  = x.z;
        orientation[9]  = y.z;
        orientation[10] = z.z;

        return translate(orientation, -center);
    }
}
