
#include <iostream>

#include <glt.hpp>

using namespace std;


// Print vector types
template <class T>
void print(glt::vec2<T> v) {
    cout << "[" << v.x << ", " << v.y << "]" << endl;
}

template <class T>
void print(glt::vec3<T> v) {
    cout << "[" << v.x << ", " << v.y << ", " << v.z << "]" << endl;
}


int main() {
    // Construct a new vector
    glt::vec2f a{2, 4};
    cout << "a = ";
    print(a);

    // Reassign values
    a.y = 1;
    cout << "a = ";
    print(a);


    // Construct from scalar
    glt::vec2f b{3.f};
    cout << "b = ";
    print(b);


    // Apply operations between vectors
    cout << "a + b = ";
    print(a + b);

    cout << "a - b = ";
    print(a - b);

    cout << "a * b = ";
    print(a * b);

    cout << "a / b = ";
    print(a / b);


    // Apply operations between vectors and scalars
    cout << "a + 2.0f = ";
    print(a + 2.0f);

    cout << "a - 2.0f = ";
    print(a - 2.0f);
    cout << "2.0f - a = ";
    print(2.0f - a);

    cout << "a * 2.0f = ";
    print(a * 2.0f);

    cout << "a / 2.0f = ";
    print(a / 2.0f);
    cout << "2.0f / a = ";
    print(2.0f / a);


    // Convert between types
    cout << "vec3f(a) = ";
    print(glt::vec3f(a));

    cout << "vec3f(a, 1) = ";
    print(glt::vec3f(a, 1));

    cout << "vec3f(1, a) = ";
    print(glt::vec3f(1, a));


    // Basic vector operations

    // Dot product between vectors
    cout << "a . b = " << glt::dot(a, b) << endl;


    // Cross product between vectors
    cout << "[1, 2, 0] x [0, 1, 0] = ";
    print(glt::cross(glt::vec3f{1, 2, 0}, glt::vec3f{0, 1, 0}));


    // Length/magnitude of vector
    cout << "|a| = " << glt::length(a) << endl;


    // Normalized form of vector
    cout << "norm(a) = ";
    print(glt::normalize(a));


    // Convert from vec2f to vec2i
    glt::vec2f f {1.5, 2.3};
    glt::vec2i i = f;
    print(static_cast<glt::vec2i>(f));

    // Convert from vec4f to vec3f
    glt::vec4f v4{1, 2, 3, 4};
    glt::vec3f v3 = v4;
    print(v3);

    return 0;
}

