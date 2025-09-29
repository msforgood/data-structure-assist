#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <iostream>
#include <stdexcept>

#define MAX_SIZE 999999   // 스택 최대 크기

typedef char ItemType;  // 스택에 저장할 데이터 타입 (괄호 검사 위해 char로 설정)

class StackType {
private:
    ItemType data[MAX_SIZE]; // 배열 기반 스택
    int top;                 // top 인덱스 (-1이면 비어있음)

public:
    // 생성자
    StackType();

    // 원소 삽입
    void push(ItemType value);

    // 원소 삭제 후 반환
    ItemType pop();

    // 현재 크기
    int size() const;

    // 상태 검사
    bool isFull() const;
    bool isEmpty() const;
};

#endif // STACKTYPE_H
