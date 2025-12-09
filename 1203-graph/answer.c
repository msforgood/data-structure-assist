// answer_official.c  그래프를 배열/연결 리스트로 구현

#include <stdio.h>    // 표준 입출력 함수
#include <stdlib.h>   // 동적 메모리 할당(malloc, free)

#define MAX_VERTICES 10   // 그래프에서 사용할 수 있는 최대 정점 개수를 상수로 정의

// ==============================
// 인접 행렬(Adjacency Matrix) 기반 그래프 구조체 정의
// ==============================

typedef struct {                         // 인접 행렬 그래프를 표현하기 위한 구조체 정의 시작
    int n;                               // 현재 그래프에 존재하는 정점의 개수를 저장할 변수
    int adj_mat[MAX_VERTICES][MAX_VERTICES]; // 정점 사이의 간선을 0/1로 표현하는 인접 행렬
} GraphMatrix;                           // 이 구조체의 이름을 GraphMatrix로 사용

// 인접 행렬 그래프 초기화 함수
void init_matrix(GraphMatrix *g) {                   // GraphMatrix 포인터를 인자로 받아 초기화하는 함수
    // NEED_TO_SOLVE
}                                                    // init_matrix 함수 끝

// 인접 행렬 그래프에 정점 하나를 추가하는 함수
void insert_vertex_matrix(GraphMatrix *g) {          // 정점을 하나 추가하는 함수(정점 번호는 0부터 차례대로 부여)
    if (g->n + 1 > MAX_VERTICES) {                   // 최대 정점 개수를 넘어가는지 검사
        printf("정점 개수 초과\n");                  // 초과할 경우 오류 메시지 출력
        return;                                      // 함수 종료
    }                                                // if 문 끝
    // NEED_TO_SOLVE
}                                                    // insert_vertex_matrix 함수 끝

// 인접 행렬 그래프에 간선을 추가하는 함수 (무방향 그래프 기준)
void insert_edge_matrix(GraphMatrix *g, int u, int v) { // 정점 u와 v 사이에 간선을 추가하는 함수
    if (u < 0 || v < 0 || u >= g->n || v >= g->n) {     // 정점 번호가 유효 범위를 벗어나는지 검사
        printf("잘못된 정점 번호입니다: %d - %d\n", u, v); // 범위를 벗어나면 경고 메시지 출력
        return;                                          // 함수 종료
    }                                                    // if 문 끝
    // NEED_TO_SOLVE
}                                                        // insert_edge_matrix 함수 끝

// 인접 행렬 그래프를 출력하는 함수
void print_matrix(GraphMatrix *g) {                      // 인접 행렬을 보기 좋게 출력하는 함수
    printf("=== Adjacency Matrix (인접 행렬) ===\n");    // 인접 행렬 출력 제목
    for (int i = 0; i < g->n; i++) {                     // 각 행(정점 i)을 순회하는 반복문
        for (int j = 0; j < g->n; j++) {                 // 각 열(정점 j)을 순회하는 반복문
            printf("%d ", g->adj_mat[i][j]);             // i와 j 사이의 간선 유무(0 또는 1)를 출력
        }                                                // 내부 for문 끝
        printf("\n");                                     // 한 행이 끝나면 줄바꿈
    }                                                    // 외부 for문 끝
}                                                        // print_matrix 함수 끝

// ==============================
// 인접 리스트(Adjacency List) 기반 그래프 구조체 정의
// ==============================

// 인접 리스트에서 사용할 노드 구조체 정의
typedef struct GraphNode {                // 인접 리스트의 한 노드를 표현하는 구조체 정의 시작
    int vertex;                           // 이 노드가 나타내는 이웃 정점 번호
    struct GraphNode *link;               // 다음 이웃 노드를 가리키는 포인터 (단순 연결 리스트 구조)
} GraphNode;                              // 이 구조체의 이름을 GraphNode로 사용

// 인접 리스트 그래프 구조체
typedef struct {                          // 인접 리스트 기반 그래프 구조체 정의 시작
    int n;                                // 현재 그래프에 존재하는 정점의 개수
    GraphNode *adj_list[MAX_VERTICES];    // 각 정점에 대한 인접 리스트의 시작 포인터 배열
} GraphList;                              // 이 구조체의 이름을 GraphList로 사용

// 인접 리스트 그래프 초기화 함수
void init_list(GraphList *g) {                        // GraphList 포인터를 받아 그래프를 초기화하는 함수
    // NEED_TO_SOLVE
}                                                     // init_list 함수 끝

// 인접 리스트 그래프에 정점 하나를 추가하는 함수
void insert_vertex_list(GraphList *g) {               // 인접 리스트 그래프에 새 정점을 추가하는 함수
    // NEED_TO_SOLVE
}                                                     // insert_vertex_list 함수 끝

// 인접 리스트 그래프에 간선을 추가하는 함수 (무방향 그래프 기준)
void insert_edge_list(GraphList *g, int u, int v) {   // 정점 u와 v 사이에 간선을 추가하는 함수
    if (u < 0 || v < 0 || u >= g->n || v >= g->n) {   // 정점 번호가 유효한지 검사
        printf("잘못된 정점 번호입니다: %d - %d\n", u, v); // 잘못된 경우 경고 메시지 출력
        return;                                       // 함수 종료
    }                                                 // if 문 끝

    // u -> v 방향 간선을 인접 리스트에 삽입
    GraphNode *node1 = (GraphNode *)malloc(sizeof(GraphNode)); // u의 인접 리스트에 들어갈 새 노드를 동적 할당
    // NEED_TO_SOLVE

    // v -> u 방향 간선을 인접 리스트에 삽입 (무방향 그래프이므로 반대 방향도 추가)
    GraphNode *node2 = (GraphNode *)malloc(sizeof(GraphNode)); // v의 인접 리스트에 들어갈 새 노드 동적 할당
    // NEED_TO_SOLVE

// 인접 리스트 그래프를 출력하는 함수
void print_list(GraphList *g) {                    // 각 정점의 인접 리스트를 화면에 출력하는 함수
    printf("=== Adjacency List (인접 리스트) ===\n"); // 인접 리스트 출력 제목
    for (int i = 0; i < g->n; i++) {               // 각 정점 i를 순회하는 반복문
        printf("정점 %d: ", i);                    // 현재 정점 번호 출력
        GraphNode *p = g->adj_list[i];             // i의 인접 리스트 시작 포인터를 p에 저장
        while (p != NULL) {                        // 리스트의 끝(NULL)까지 순회
            printf("%d -> ", p->vertex);           // 이웃 정점 번호를 출력하고 화살표로 연결 상태를 표현
            p = p->link;                           // 다음 이웃 노드로 이동
        }                                          // while문 끝
        printf("NULL\n");                          // 리스트의 끝을 NULL로 표시하고 줄바꿈
    }                                              // for문 끝
}                                                  // print_list 함수 끝

// 인접 리스트 그래프에서 동적 할당된 모든 노드를 해제하는 함수
void free_list(GraphList *g) {                     // 동적 메모리를 해제하여 메모리 누수를 방지하는 함수
    for (int i = 0; i < g->n; i++) {               // 각 정점의 인접 리스트를 순회하는 반복문
        GraphNode *p = g->adj_list[i];             // 현재 정점 i의 리스트 시작 포인터를 p로 설정
        while (p != NULL) {                        // 리스트 끝(NULL)까지 반복
            GraphNode *temp = p;                   // 현재 노드 포인터를 temp에 저장
            p = p->link;                           // p를 다음 노드로 이동
            free(temp);                            // temp가 가리키는 노드를 해제
        }                                          // while문 끝
        g->adj_list[i] = NULL;                     // 해당 정점의 리스트 시작 포인터를 NULL로 초기화
    }                                              // for문 끝
}                                                  // free_list 함수 끝

// ==============================
// main 함수: 두 종류의 그래프를 생성하고 출력하는 테스트 코드
// ==============================

int main(void) {                                   // 프로그램의 시작점인 main 함수 정의
    GraphMatrix g_mat;                             // 인접 행렬 그래프를 저장할 변수 선언
    GraphList g_list;                              // 인접 리스트 그래프를 저장할 변수 선언

    init_matrix(&g_mat);                           // 인접 행렬 그래프 구조를 초기화
    init_list(&g_list);                            // 인접 리스트 그래프 구조를 초기화

    // 정점 4개(0, 1, 2, 3)를 추가하는 예제
    for (int i = 0; i < 4; i++) {                  // 0부터 3까지 총 4개의 정점을 추가하기 위한 반복문
        insert_vertex_matrix(&g_mat);              // 인접 행렬 그래프에 정점 추가
        insert_vertex_list(&g_list);               // 인접 리스트 그래프에 정점 추가
    }                                              // for문 끝

    // 간선들을 추가하여 간단한 무방향 그래프를 구성
    // 예: 0-1, 0-2, 1-2, 2-3
    insert_edge_matrix(&g_mat, 0, 1);              // 인접 행렬 그래프에 정점 0과 1 사이의 간선 추가
    insert_edge_matrix(&g_mat, 0, 2);              // 인접 행렬 그래프에 정점 0과 2 사이의 간선 추가
    insert_edge_matrix(&g_mat, 1, 2);              // 인접 행렬 그래프에 정점 1과 2 사이의 간선 추가
    insert_edge_matrix(&g_mat, 2, 3);              // 인접 행렬 그래프에 정점 2와 3 사이의 간선 추가

    insert_edge_list(&g_list, 0, 1);               // 인접 리스트 그래프에 정점 0과 1 사이의 간선 추가
    insert_edge_list(&g_list, 0, 2);               // 인접 리스트 그래프에 정점 0과 2 사이의 간선 추가
    insert_edge_list(&g_list, 1, 2);               // 인접 리스트 그래프에 정점 1과 2 사이의 간선 추가
    insert_edge_list(&g_list, 2, 3);               // 인접 리스트 그래프에 정점 2와 3 사이의 간선 추가

    // 두 그래프 표현을 각각 출력해서 비교해 보기
    print_matrix(&g_mat);                          // 인접 행렬을 화면에 출력
    printf("\n");                                   // 가독성을 위해 한 줄 띄우기
    print_list(&g_list);                           // 인접 리스트를 화면에 출력

    free_list(&g_list);                            // 인접 리스트에서 동적 할당된 노드들을 모두 해제

    return 0;                                      // 프로그램을 정상 종료했음을 운영체제에 알림
}                                                  // main 함수 끝
