// answer.cpp
#include "answer.hpp"

// 1) 값 전달
void swap_value(int a, int b) {
    int temp = NEED_TO_SOLVE;
    NEED_TO_SOLVE = NEED_TO_SOLVE;
    NEED_TO_SOLVE = NEED_TO_SOLVE;
    cout << "[swap_value 내부] a=" << a << ", b=" << b << endl;
}

// 2) 참조 전달
void swap_ref(int &a, int &b) {
    int temp = NEED_TO_SOLVE;
    NEED_TO_SOLVE = NEED_TO_SOLVE;
    NEED_TO_SOLVE = NEED_TO_SOLVE;
    cout << "[swap_ref 내부] a=" << a << ", b=" << b << endl;
}

// 3) 주소 전달
void swap_pointer(int *a, int *b) {
    int temp = NEED_TO_SOLVE;
    NEED_TO_SOLVE = NEED_TO_SOLVE;
    NEED_TO_SOLVE = NEED_TO_SOLVE;
    cout << "[swap_pointer 내부] *a=" << *a << ", *b=" << *b << endl;
}

// 4) increment
void increment(int *ptr) {
    NEED_TO_SOLVE;
    cout << "[increment 내부] *ptr=" << NEED_TO_SOLVE << endl;
}
