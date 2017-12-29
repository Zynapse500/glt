//
// Created by Christofer Nolander on 2017-12-27.
//

#pragma once


#include "vec_core.hpp"


namespace glt {

    // Define common vector types

    // 2D vectors
    typedef vec2<int> vec2i;
    typedef vec2<float> vec2f;
    typedef vec2<double> vec2d;

    // 3D vectors
    typedef vec3<int> vec3i;
    typedef vec3<float> vec3f;
    typedef vec3<double> vec3d;

    // 4D vectors
    typedef vec4<int> vec4i;
    typedef vec4<float> vec4f;
    typedef vec4<double> vec4d;



    // Define equality operators
    template <class T>
    bool operator==(const glt::vec2<T>& a, const glt::vec2<T>& b) {
        return (a.x == b.x && a.y == b.y);
    }

    template <class T>
    bool operator==(const glt::vec3<T>& a, const glt::vec3<T>& b) {
        return (a.x == b.x && a.y == b.y && a.z == b.z);
    }

    template <class T>
    bool operator==(const glt::vec4<T>& a, const glt::vec4<T>& b) {
        return (a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w);
    }


    // Define inequality operators
    template <class T>
    bool operator!=(const glt::vec2<T>& a, const glt::vec2<T>& b) {
        return (a.x != b.x && a.y != b.y);
    }

    template <class T>
    bool operator!=(const glt::vec3<T>& a, const glt::vec3<T>& b) {
        return (a.x != b.x && a.y != b.y && a.z != b.z);
    }

    template <class T>
    bool operator!=(const glt::vec4<T>& a, const glt::vec4<T>& b) {
        return (a.x != b.x && a.y != b.y && a.z != b.z && a.w != b.w);
    }
}
