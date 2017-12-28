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



int main() {
    glt::mat4f a;
    glt::mat4f b;

    glt::mat4f r = a * b;

    glt::mat4f t = glt::rotate(a, 3.14159265359f, {1, 0, 0});

    glt::vec4f p{1, 2, 3, 1};
    glt::vec4f res = t * p;

    print(res);
}