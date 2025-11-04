#include <stdio.h>          // printf
#include <stdlib.h>         // rand
#include <time.h>           // clock
#include "main.hpp"         // ArrayList/LinkedList 선언

// ------- 초간단 시간 도우미(ms) -------
static long long ms(clock_t list, clock_t b){ return (long long)((b - list) * 1000.0 / CLOCKS_PER_SEC); }

// ------- 배열 앞삽입(실험용 로컬 헬퍼) -------
static void al_insert_front(ArrayList* L, int x){
    if(L->n >= AL_CAP) return;                // 용량 초과면 무시
    int j = L->n;                              // 뒤에서부터
    while(j > 0){ L->list[j] = L->list[j-1]; j--; } // 모두 한 칸 밀기
    L->list[0] = x;                               // 맨 앞에 값 쓰기
    L->n = L->n + 1;                           // 개수 증가
}

// ------- 배열 앞삭제(실험용 로컬 헬퍼) -------
static int al_pop_front(ArrayList* L){
    if(L->n == 0) return -1;                   // 비었으면 -1
    int v = L->list[0];                           // 반환값 보관
    int j = 1;                                 // 두 번째부터
    while(j < L->n){ L->list[j-1] = L->list[j]; j++; } // 한 칸씩 당기기
    L->n = L->n - 1;                           // 개수 감소
    return v;                                  // 반환
}

// ------- 연결리스트 앞삭제(실험용 로컬 헬퍼: push_front의 반대) -------
static int ll_pop_front(LinkedList* L){
    if(L->head == NULL) return -1;             // 비었으면 -1
    Node* d = L->head;                          // 삭제할 노드
    int v = d->x;                               // 값 보관
    L->head = d->next;                          // Head를 다음으로
    free(d);                                    // 노드 해제
    L->n = L->n - 1;                            // 개수 감소
    return v;                                   // 반환
}

int main(void){
    // 파라미터(느리면 줄이고, 너무 빠르면 늘리세요)
    const int FRONT_OP_ROUNDS = 200;            // 앞삽입/앞삭제 라운드 수
    const int FRONT_OP_COUNT  = 800;            // 한 라운드당 원소 개수(<= AL_CAP)
    const int N_BUILD         = 100000;           // 인덱스 조회용 리스트 크기(<= AL_CAP)
    const int REPEAT_GET      = 10000;         // 인덱스 조회 반복 횟수

    srand(12345);

    printf("== Linked List vs Array ==\n");
    printf("- 비교 항목: 추가/삭제(HEAD) / 인덱스 조회\n\n");

    // --------------------------------------------------------------------
    // 1) 추가/삭제(Head 기준): Linked List가 더 빠른 것을 보여주기
    //    - Array: 앞삽입/앞삭제마다 '전부 밀기/당기기' → O(N) 이동
    //    - Linked: 포인터만 바꿔 Head 연결 변경 → O(1)
    // --------------------------------------------------------------------
    {
        ArrayList A; al_init(&A);
        clock_t a0 = clock();
        for(int r=0; r<FRONT_OP_ROUNDS; ++r){
            for(int i=0; i<FRONT_OP_COUNT; ++i) al_insert_front(&A, i);  // 앞삽입 반복
            for(int i=0; i<FRONT_OP_COUNT; ++i) al_pop_front(&A);        // 앞삭제 반복
        }
        clock_t a1 = clock();

        LinkedList L; ll_init(&L);
        clock_t l0 = clock();
        for(int r=0; r<FRONT_OP_ROUNDS; ++r){
            for(int i=0; i<FRONT_OP_COUNT; ++i) ll_insert(&L, 0, i);    // 앞삽입 반복(O(1))
            for(int i=0; i<FRONT_OP_COUNT; ++i) ll_pop_front(&L);        // 앞삭제 반복(O(1))
        }
        clock_t l1 = clock();

        printf("[추가/삭제(Head)] Array = %lld ms, Linked = %lld ms\n", ms(a0,a1), ms(l0,l1));
        printf("  해석: Array는 앞에서 넣고 빼려면 뒤 원소들을 '밀고/당겨야' 해서 느림(O(N)).\n");
        printf("       Linked는 Head 포인터만 바꾸면 되므로 빠름(O(1)).\n\n");
    }

    // --------------------------------------------------------------------
    // 2) 인덱스 조회(임의 접근): Array가 더 빠른 것을 보여주기
    //    - Array: list[i]가 즉시 주소 계산 → O(1)
    //    - Linked: i번째까지 next를 따라감 → O(N)
    // --------------------------------------------------------------------
    {
        // 동일 데이터 구성
        ArrayList A; al_init(&A);
        for(int i=0;i<N_BUILD;i++) al_append(&A, i);      // 0..N-1 (연속)

        LinkedList L; ll_init(&L);
        for(int i=0;i<N_BUILD;i++) ll_insert(&L, 0, i);  // Head에 넣어서 크기만 맞추기

        long long guardA = 0, guardL = 0;                 // 최적화 방지용 합계

        clock_t a0 = clock();
        for(int k=0;k<REPEAT_GET;k++){
            int idx = rand() % N_BUILD;                   // 무작위 인덱스
            guardA += al_get(&A, idx);                    // O(1)
        }
        clock_t a1 = clock();

        clock_t l0 = clock();
        for(int k=0;k<REPEAT_GET;k++){
            int idx = rand() % N_BUILD;                   // 무작위 인덱스
            guardL += ll_get(&L, idx);                    // O(N)
        }
        clock_t l1 = clock();

        printf("[인덱스 조회]   Array = %lld ms, Linked = %lld ms (sum %lld/%lld)\n",
               ms(a0,a1), ms(l0,l1), guardA, guardL);
        printf("  해석: Array는 연속 메모리라 list[i]에 즉시 접근(O(1))이 가능.\n");
        printf("       Linked는 i번째를 찾으려면 Head부터 i번 이동(O(N))이라 느림.\n");
    }

    return 0;
}
