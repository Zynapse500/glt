//
// Created by Christofer Nolander on 2017-12-28.
//

#pragma once

#include "vec2.hpp"
#include "vec3.hpp"


namespace glt {

    // Dot product
    template <class T>
    inline T dot(const Vec2<T>& a, const Vec2<T>& b) {
        return a.x * b.x + a.y * b.y;
    }

    template <class T>
    inline T dot(const Vec3<T>& a, const Vec3<T>& b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }


    // Return the length (magnitude) of a vector
    template <class T>
    inline T length(const Vec2<T>& a) {
        return sqrt(a.x * a.x + a.y * a.y);
    }

    template <class T>
    inline T length(const Vec3<T>& a) {
        return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    }


    // Return the squared length (magnitude) of a vector
    template <class T>
    inline T squaredLength(const Vec2<T>& a) {
        return a.x * a.x + a.y * a.y;
    }

    template <class T>
    inline T squaredLength(const Vec3<T>& a) {
        return a.x * a.x + a.y * a.y + a.z * a.z;
    }


    // Return the normalized form of this vector
    template <class T>
    inline Vec2<T> normalize(const Vec2<T>& a) {
        return a / length(a);
    }

    template <class T>
    inline Vec3<T> normalize(const Vec3<T>& a) {
        return a / length(a);
    }
}

