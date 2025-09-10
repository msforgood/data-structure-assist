// answer.hpp
#pragma once
#include <iostream>
using namespace std;

#define NEED_TO_SOLVE /* TODO */

// 1) 값 전달 (swap1)
void swap_value(int a, int b);

// 2) 참조 전달 (swap2)
void swap_ref(int &a, int &b);

// 3) 주소 전달 (swap3)
void swap_pointer(int *a, int *b);

// 4) increment
void increment(int *ptr);
