// main.cpp
#include <iostream>
// 둘 중 하나만 선택해서 include
#include "answer_official.hpp"
// #include "answer.hpp"

using namespace std;

int main() {
    int x = 3, y = 5;

    cout << "=== 1) Call by Value (swap_value) ===" << endl;
    cout << "swap 전: x=" << x << ", y=" << y << endl;
    swap_value(x, y);
    cout << "swap 후: x=" << x << ", y=" << y << " (변화 없음)" << endl << endl;

    cout << "=== 2) Call by Reference (swap_ref) ===" << endl;
    cout << "swap 전: x=" << x << ", y=" << y << endl;
    swap_ref(x, y);
    cout << "swap 후: x=" << x << ", y=" << y << " (실제 값 바뀜)" << endl << endl;

    cout << "=== 3) Call by Address (swap_pointer) ===" << endl;
    cout << "swap 전: x=" << x << ", y=" << y << endl;
    swap_pointer(&x, &y);
    cout << "swap 후: x=" << x << ", y=" << y << " (실제 값 바뀜)" << endl << endl;

    cout << "=== 4) increment(&x) ===" << endl;
    cout << "증가 전 x=" << x << endl;
    increment(&x);
    cout << "증가 후 x=" << x << endl << endl;

    return 0;
}
