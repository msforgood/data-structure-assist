#include <iostream>
#include "answer.hpp"

using namespace std;

int main() {
    int x = 3, y = 5;

    cout << "=== 1) swap_value (Call by Value) ===" << endl;
    x = 3; y = 5;
    cout << "swap 전: " << x << ", " << y << endl;
    swap_value(x, y);
    cout << "swap 후: " << x << ", " << y << " (안 바뀜)" << endl << endl;

    cout << "=== 2) swap_ref (Call by Reference) ===" << endl;
    x = 3; y = 5;
    cout << "swap 전: " << x << ", " << y << endl;
    swap_ref(x, y);
    cout << "swap 후: " << x << ", " << y << " (바뀜)" << endl << endl;

    cout << "=== 3) swap_pointer_deref (Call by Address) ===" << endl;
    x = 3; y = 5;
    cout << "swap 전: " << x << ", " << y << endl;
    swap_pointer_deref(&x, &y);
    cout << "swap 후: " << x << ", " << y << " (바뀜)" << endl << endl;

    cout << "=== 4) swap_pointer_var (포인터 변수 교환) ===" << endl;
    x = 3; y = 5;
    cout << "swap 전: " << x << ", " << y << endl;
    swap_pointer_var(&x, &y);
    cout << "swap 후: " << x << ", " << y << " (안 바뀜)" << endl << endl;

    cout << "=== 5) increment_pointer(&x) ===" << endl;
    cout << "증가 전 x=" << x << endl;
    increment_pointer(&x);
    cout << "증가 후 x=" << x << endl << endl;

    return 0;
}
