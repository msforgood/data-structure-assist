// answer.hpp
#pragma once
#include <iostream>
using namespace std;

#define NEED_TO_SOLVE /* TODO */

void swap_value(int a, int b);           // Call by Value
void swap_ref(int &a, int &b);           // Call by Reference
void swap_pointer_deref(int *a, int *b); // Call by Address (역참조)
void swap_pointer_var(int *a, int *b);   // 포인터 변수 교환
void increment_pointer(int *ptr);        // 포인터로 값 증가