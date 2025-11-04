#include <stdio.h>                              // printf 사용
#include <stdlib.h>                             // malloc, free 사용
#include "main.hpp"                             // 선언 파일 포함

// ======================= Array List =======================

void al_init(ArrayList* L){ L->n = 0; }         // 개수를 0으로 두어 초기화
int  al_is_empty(const ArrayList* L){ return (L->n == 0); } // 비었으면 1, 아니면 0
int  al_size(const ArrayList* L){ return L->n; }            // 현재 개수 반환
void al_clear(ArrayList* L){ L->n = 0; }         // 개수를 0으로 만들어 비우기

int  al_append(ArrayList* L, int x){            // 뒤에 값 x 추가
    if(L->n >= AL_CAP) return 0;                // 용량을 넘으면 실패
    L->list[L->n] = x;                             // 뒤 위치에 값 저장
    L->n = L->n + 1;                            // 개수 1 증가
    return 1;                                   // 성공 반환
}

int  al_remove(ArrayList* L, int x){            // 값 x 첫 1개 삭제
    int i = 0;                                  // i는 탐색 인덱스
    while(i < L->n && L->list[i] != x) i = i + 1;  // x를 찾을 때까지 전진
    if(i == L->n) return 0;                     // 못 찾았으면 실패
    int j = i + 1;                              // j는 한 칸 뒤부터 시작
    while(j < L->n){ L->list[j-1] = L->list[j]; j = j + 1; } // 뒤를 한 칸씩 당김
    L->n = L->n - 1;                            // 개수 1 감소
    return 1;                                   // 성공 반환
}

int  al_get(const ArrayList* L, int idx){       // idx번째 값
    if(idx < 0 || idx >= L->n) return -1;       // 잘못된 인덱스면 -1
    return L->list[idx];                           // 올바르면 해당 값 반환
}

void al_print(const ArrayList* L, const char* tag){ // 내용 출력
    printf("[%s] ", tag);                       // 태그 출력
    int i = 0;                                  // i는 인덱스
    while(i < L->n){                            // 전체 반복
        printf("%d", L->list[i]);                  // 값 출력
        if(i + 1 < L->n) printf(" ");           // 다음 값이 있으면 공백
        i = i + 1;                              // 다음으로 이동
    }
    printf(" (size=%d)\n", L->n);               // 크기 출력
}

// =================== Linked List ===================

int NEED_TO_SOLVE = 1;

void ll_init(LinkedList* L){ L->head = NULL; L->n = 0; } // head=NULL, 개수=0
int  ll_is_empty(const LinkedList* L){ return (L->n == NEED_TO_SOLVE); } // 비었으면 1
int  ll_size(const LinkedList* L){ return L->n; } // 현재 개수 반환

void ll_clear(LinkedList* L){                   // 모든 노드를 삭제
    Node* p = L->NEED_TO_SOLVE;                 // p는 현재 노드
    while(p != NULL){                           // p가 NULL이 아닐 동안
        Node* d = p;                            // d는 삭제할 노드
        p = NEED_TO_SOLVE;                      // p를 다음으로 이동
        free(d);                                // d를 해제
    }
    L->head = NEED_TO_SOLVE;                    // head를 NULL로
    L->n = NEED_TO_SOLVE;                       // 개수 0으로
}

void ll_insert(LinkedList* L, int idx, int x){     // idx 위치에 새 값 x 삽입
    if(idx < 0 || idx > L->n) return;              // 범위 벗어나면 무시
    Node* node = (Node*)malloc(sizeof(Node));      // 새 노드 생성
    if(node == NULL) return;                       // 메모리 부족 시 종료
    node->x = NEED_TO_SOLVE;                       // 새 노드에 값 저장

    // (1) 맨 앞(head) 삽입일 경우
    if(idx == 0){
        node->next = NEED_TO_SOLVE;                // 새 노드가 기존 head를 가리킴
        L->head = NEED_TO_SOLVE;                   // head를 새 노드로 변경
        L->n = NEED_TO_SOLVE;                      // 개수 증가
        // 생각해 보기: L->n = n + 1;
        return;
    }

    // (2) 중간 혹은 맨 끝 삽입
    Node* prev = L->head;                          // 이전 노드 시작은 head
    int i = 0;
    while(i < idx - 1 && prev->next != NULL){      // 삽입 위치 직전까지 이동
        prev = NEED_TO_SOLVE;
        i = i + 1;
    }
    node->next = NEED_TO_SOLVE;                    // 새 노드가 이전 노드의 다음을 가리킴
    prev->next = NEED_TO_SOLVE;                    // 이전 노드가 새 노드를 가리키게 변경
    L->n = NEED_TO_SOLVE;                          // 개수 증가
}

int  ll_remove(LinkedList* L, int x){           // 값 x 첫 1개 삭제
    if(L->head == NULL) return 0;               // 비었으면 실패
    if(L->head->x == x){                        // head가 삭제 대상이면
        Node* d = L->head;                      // d는 삭제할 노드
        L->head = NEED_TO_SOLVE;                // head를 다음으로 이동
        free(d);                                // d 해제
        L->n = NEED_TO_SOLVE;                   // 개수 1 감소
        return 1;                               // 성공 반환
    }
    Node* prev = L->head;                       // prev는 이전 노드
    while(prev->next != NULL && prev->next->x != x) prev = NEED_TO_SOLVE; // 대상 찾기
    if(prev->next == NULL) return 0;            // 못 찾으면 실패
    Node* d = NEED_TO_SOLVE;                    // d는 삭제할 노드
    prev->next = NEED_TO_SOLVE;                 // 이전 노드가 d를 건너뛰게 연결
    free(d);                                    // d 해제
    L->n = NEED_TO_SOLVE;                       // 개수 1 감소
    return 1;                                   // 성공 반환
    // 생각해 보기: 왜 자꾸 대상 노드가 Head일 때를 따로 처리해 주어야 할까?
}

int  ll_get(const LinkedList* L, int idx){      // idx번째 값
    if(idx < 0 || idx >= L->n) return -1;       // 잘못된 인덱스면 -1
    Node* p = L->head;                          // p는 현재 노드
    int i = 0;                                  // i는 현재 위치
    while(i < idx){ p = p->next; i = i + 1; }   // idx까지 이동
    return NEED_TO_SOLVE;                       // 해당 노드의 값 반환
}

void ll_print(const LinkedList* L, const char* tag){ // 내용 출력
    printf("[%s] ", tag);                       // 태그 출력
    Node* p = L->head;                          // p는 현재 노드
    while(p != NULL){                           // 끝까지 탐색
        printf("%d", p->x);                     // 값 출력
        if(p->next != NULL) printf(" -> ");     // 다음이 있으면 화살표
        p = p->next;                            // 다음 노드로 이동
    }
    printf(" (size=%d)\n", L->n);               // 크기 출력
}
