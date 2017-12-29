//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include "mat2.hpp"
#include "mat3.hpp"
#include "mat4.hpp"


namespace glt {


    // Find the determinant of a matrix
    template<class T>
    inline T determinant(const mat2<T> &m) {
        return m[0] * m[3] - m[1] * m[2];
    }

    template<class T>
    inline T determinant(const mat3<T> &m) {
        return (
                m[0] * (m[4] * m[8] - m[5] * m[7]) -
                m[1] * (m[3] * m[8] - m[5] * m[6]) +
                m[2] * (m[3] * m[7] - m[4] * m[6])
        );
    }

    template<class T>
    inline T determinant(const mat4<T> &m) {
        return (
                m[0] * (determinant(mat3<T>{{
                                                     m[5], m[6], m[7],
                                                     m[9], m[10], m[11],
                                                     m[13], m[14], m[15],
                                             }})) -
                m[1] * (determinant(mat3<T>{{
                                                     m[4], m[6], m[7],
                                                     m[8], m[10], m[11],
                                                     m[12], m[14], m[15],
                                             }})) +
                m[2] * (determinant(mat3<T>{{
                                                     m[4], m[5], m[7],
                                                     m[8], m[9], m[11],
                                                     m[12], m[13], m[15],
                                             }})) -
                m[3] * (determinant(mat3<T>{{
                                                     m[4], m[5], m[6],
                                                     m[8], m[9], m[10],
                                                     m[12], m[13], m[14],
                                             }}))
        );
    }


    // The transpose of a matrix
    template <class T>
    inline mat4<T> transpose(const mat4<T>& m) {
        mat4<T> result = m;

        for (int col = 0; col < 4; ++col) {
            for (int row = 0; row < 4; ++row) {
                if (col != row) {
                    result[4*col + row] = m[col + 4*row];
                }
            }
        }

        return result;
    }


    // The inverse of a matrix
    template <class T>
    inline mat4<T> inverse(const mat4<T>& m) {
        mat4<T> minor{0};

        for (int col = 0; col < 4; ++col) {
            for (int row = 0; row < 4; ++row) {
                int index = 0;

                mat3<T> sub{0};

                for (int i = 0; i < 4; ++i) {
                    if (i == col) continue;
                    for (int j = 0; j < 4; ++j) {
                        if (j == row) continue;

                        sub[index] = m[i + 4 * j];
                        index++;
                    }
                }

                minor[col + 4 * row] = determinant(sub);
            }
        }

        // Find cofactor
        for (int col = 0; col < 4; ++col) {
            for (int row = 0; row < 4; ++row) {
                if ((col + row) % 2) {
                    minor[col + 4 * row] *= T(-1);
                }
            }
        }

        // Calculate determinant
        T det{0};
        for (int i = 0; i < 4; ++i) {
            det += m[i] * minor[i];
        }

        // Transpose to find adjoin
        minor = transpose(minor);

        // Calculate inverse
        return (T(1) / det) * minor;
    }



    // Translate matrix
    template<class T>
    mat4<T> translate(const mat4<T> &m, const vec3<T> &amount) {
        // Translation matrix
        mat4<T> translation;

        translation[12] = amount.x;
        translation[13] = amount.y;
        translation[14] = amount.z;

        return m * translation;
    }


    // Scale matrix
    template<class T>
    mat4<T> scale(const mat4<T> &m, const vec3<T> &amount) {
        // Scale matrix
        mat4<T> scale;

        scale[0] = amount.x;
        scale[5] = amount.y;
        scale[10] = amount.z;

        return scale * m;
    }


    // Rotate a matrix around an axis by an angle specified in radians
    template<class T>
    mat4<T> rotate(const mat4<T> &m, T angle, const vec3<T> &axis) {
        // Rotation matrix
        mat4<T> rotation;

        T x = axis.x;
        T y = axis.y;
        T z = axis.z;

        T co = cos(angle);
        T si = sin(angle);

        T m_co = 1 - co;

        rotation[0] = co + x * x * m_co;
        rotation[1] = x * y * m_co - z * si;
        rotation[2] = x * z * m_co + y * si;
        rotation[4] = x * y * m_co + z * si;
        rotation[5] = co + y * y * m_co;
        rotation[6] = y * z * m_co - x * si;
        rotation[8] = x * z * m_co - y * si;
        rotation[9] = y * z * m_co + x * si;
        rotation[10] = co + z * z * m_co;

        return rotation * m;
    }


    // Create a look at orientation matrix
    // From center, orient vector to point at target
    template<class T>
    mat4<T> lookAt(vec3<T> center, vec3<T> target, vec3<T> up) {

        // The new directions of the axes
        vec3<T> z = normalize(center - target);
        vec3<T> x = normalize(cross(up, z));
        vec3<T> y = cross(z, x);

        // The orientation matrix
        mat4<T> orientation;

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
