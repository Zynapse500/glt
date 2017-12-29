//
// Created by Christofer Nolander on 2017-12-28.
//

#include <iostream>
#include <glt.hpp>


using namespace std;

template <class T>
void print(glt::vec4<T> v) {
    cout << "[" << v.x << ", " << v.y << ", " << v.z <<", " << v.w << "]" << endl;
}


template <class T>
void print(glt::mat4<T> m) {
    cout << "[" << endl;

    for (int i = 0; i < 4; ++i) {
        cout << "  ";
        for (int j = 0; j < 4; ++j) {
            if (m[i + 4 * j] == -0) {
                m[i + 4 * j] = 0;
            }
            cout << m[i + 4 * j] << ", ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}


int main() {
    glt::mat4f a;
    glt::mat4f b;

    glt::mat4f r = a * b;

    glt::vec4f p{0, 0, 0, 1};

    glt::mat4f t1 = glt::translate(glt::mat4f(), {3, 1, 0});
    print(t1 * p);

    glt::mat4f t2 = glt::translate(t1, {2, -1, 4});
    print(t2 * p);
}