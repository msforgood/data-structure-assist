#ifndef MAIN_HPP
#define MAIN_HPP

#include <stddef.h>              // size_t 사용을 위해 포함

// ======================= Array List =======================

#define AL_CAP 1000              // 배열 용량을 상수로 정의

typedef struct {                 // 배열 리스트를 나타내는 구조체
    int list[AL_CAP];               // 실제 데이터를 담을 배열
    int n;                       // 현재 저장된 개수
} ArrayList;

void al_init(ArrayList* L);                      // 리스트 초기화
int  al_is_empty(const ArrayList* L);            // 비었는지 확인
int  al_size(const ArrayList* L);                // 크기 반환
void al_clear(ArrayList* L);                     // 비우기
int  al_append(ArrayList* L, int x);             // 뒤에 추가(성공1/실패0)
int  al_remove(ArrayList* L, int x);             // 값 x 첫 1개 삭제
int  al_get(const ArrayList* L, int idx);        // idx번째 값(잘못되면 -1)
void al_print(const ArrayList* L, const char* tag); // 내용 출력

// =================== Linked List ===================

typedef struct Node {            // 연결 리스트의 노드
    int x;                       // 데이터 값
    struct Node* next;           // 다음 노드를 가리키는 포인터
} Node;

typedef struct {                 // 연결 리스트를 나타내는 구조체
    Node* head;                  // 머리(첫 노드)를 가리키는 포인터
    int n;                       // 현재 저장된 개수
} LinkedList;

void ll_init(LinkedList* L);                     // 리스트 초기화
int  ll_is_empty(const LinkedList* L);           // 비었는지 확인
int  ll_size(const LinkedList* L);               // 크기 반환
void ll_clear(LinkedList* L);                    // 모두 삭제
void ll_push_front(LinkedList* L, int x);        // 머리에 삽입
void ll_insert(LinkedList* L, int idx, int x);   // idx 위치에 삽입
int  ll_remove(LinkedList* L, int x);            // 값 x 첫 1개 삭제
int  ll_get(const LinkedList* L, int idx);       // idx번째 값(잘못되면 -1)
void ll_print(const LinkedList* L, const char* tag); // 내용 출력

#endif // MAIN_HPP
