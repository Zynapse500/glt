//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include <cmath>


#include "vec4.hpp"
#include "vec3.hpp"
#include "vec2.hpp"


namespace glt {

    // Dot product
    ///////////////////////////
    // a . b = |a||b| cos(theta)
    ///////////////////////////
    template<class T>
    inline T dot(const vec2<T> &a, const vec2<T> &b) {
        return a.x * b.x + a.y * b.y;
    }

    template<class T>
    inline T dot(const vec3<T> &a, const vec3<T> &b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    template<class T>
    inline T dot(const vec4<T> &a, const vec4<T> &b) {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }


    // Return the squared length (magnitude) of a vector

    ///////////////////////////
    // a . b = |a||b| cos(theta)
    // Therefore:
    // a . a = |a||a|
    ///////////////////////////

    template<class T>
    inline T squaredLength(const vec2<T> &a) {
        return dot(a, a);
    }

    template<class T>
    inline T squaredLength(const vec3<T> &a) {
        return dot(a, a);
    }

    template<class T>
    inline T squaredLength(const vec4<T> &a) {
        return dot(a, a);
    }


    // Return the length (magnitude) of a vector
    template<class T>
    inline T length(const vec2<T> &a) {
        return sqrt(squaredLength(a));
    }

    template<class T>
    inline T length(const vec3<T> &a) {
        return sqrt(squaredLength(a));
    }

    template<class T>
    inline T length(const vec4<T> &a) {
        return sqrt(squaredLength(a));
    }


    // Return the normalized form of this vector
    template<class T>
    inline vec2<T> normalize(const vec2<T> &a) {
        return a / length(a);
    }

    template<class T>
    inline vec3<T> normalize(const vec3<T> &a) {
        return a / length(a);
    }

    template<class T>
    inline vec4<T> normalize(const vec4<T> &a) {
        return a / length(a);
    }


    // Return the cross product of two vectors
    template<class T>
    inline vec3<T> cross(const vec3<T> &a, const vec3<T> &b) {
        return {
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x
        };
    }


    // Implement rounding for vectors

    // Round downward
    template<class T>
    vec2<T> floor(const vec2<T> &v) {
        return {
                ::floor((v.x)),
                ::floor((v.y))
        };
    }

    template<class T>
    vec3<T> floor(const vec3<T> &v) {
        return {
                ::floor((v.x)),
                ::floor((v.y)),
                ::floor((v.z)),
        }
    }

    template<class T>
    vec4<T> floor(const vec4<T> &v) {
        return {
                ::floor((v.x)),
                ::floor((v.y)),
                ::floor((v.z)),
                ::floor((v.w))
        };
    }


    // Round to nearest whole number
    template<class T>
    vec2<T> round(const vec2<T> &v) {
        return {
                ::round((v.x)),
                ::round((v.y))
        };
    }

    template<class T>
    vec3<T> round(const vec3<T> &v) {
        return {
                ::round((v.x)),
                ::round((v.y)),
                ::round((v.z))
        };
    }

    template<class T>
    vec4<T> round(const vec4<T> &v) {
        return {
                ::round((v.x)),
                ::round((v.y)),
                ::round((v.z)),
                ::round((v.w))
        };
    }


    // Round upward
    template<class T>
    vec2<T> ceil(const vec2<T> &v) {
        return {
                ::ceil((v.x)),
                ::ceil((v.y))
        };
    }

    template<class T>
    vec3<T> ceil(const vec3<T> &v) {
        return {
                ::ceil((v.x)),
                ::ceil((v.y)),
                ::ceil((v.z))
        };
    }

    template<class T>
    vec4<T> ceil(const vec4<T> &v) {
        return {
                ::ceil((v.x)),
                ::ceil((v.y)),
                ::ceil((v.z)),
                ::ceil((v.w))
        };
    }
}

