#include "answer.hpp"

void swap_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "[swap_value 내부] a=" << a << ", b=" << b << endl;
}

void swap_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "[swap_ref 내부] a=" << a << ", b=" << b << endl;
}

void swap_pointer_deref(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "[swap_pointer_deref 내부] a=" << a << ", b=" << b << endl;
}

void swap_pointer_var(int *a, int *b) {
    int *temp = a;
    a = b;
    b = temp;
    cout << "[swap_pointer_var 내부] a=" << a << ", b=" << b << endl;
}

void increment_pointer(int *ptr) {
    (*ptr)++;
    cout << "[increment_pointer 내부] *ptr=" << *ptr << endl;
}