// answer_official.c

#include <stdio.h>

#define MAX_VERTICES 20

// 그래프 구조체: 정점 개수 + 인접 행렬
typedef struct {
    int numVertices;                   // 실제 사용 중인 정점 개수
    int adj[MAX_VERTICES][MAX_VERTICES]; // 인접 행렬 (0: 없음, 1: 간선 존재)
} Graph;

// 함수 프로토타입 선언
void initGraph(Graph *g, int numVertices);
void addEdge(Graph *g, int from, int to);
void printAdjMatrix(Graph *g);
void DFS(Graph *g, int start);
void BFS(Graph *g, int start);

// 그래프 초기화: 모든 간선을 0으로 만들기
void initGraph(Graph *g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// 무방향 그래프 기준 간선 추가
void addEdge(Graph *g, int from, int to) {
    if (from < 0 || from >= g->numVertices) return;
    if (to   < 0 || to   >= g->numVertices) return;

    g->adj[from][to] = 1;
    g->adj[to][from] = 1; // 무방향 그래프이므로 반대 방향도 1
}

// 인접 행렬 출력 (디버깅/시각화용)
void printAdjMatrix(Graph *g) {
    printf("\n[Adjacency Matrix]\n    ");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < g->numVertices; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            printf("%2d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// DFS: 스택을 이용한 깊이 우선 탐색
void DFS(Graph *g, int start) {
    int visited[MAX_VERTICES] = {0}; // 방문 여부 배열
    int stack[MAX_VERTICES];
    int top = -1;

    if (start < 0 || start >= g->numVertices) {
        printf("\n[DFS] 잘못된 시작 정점입니다.\n");
        return;
    }

    // 시작 정점 스택에 push
    stack[++top] = start;

    printf("\n[DFS] Start from %d\n", start);

    while (top != -1) {      // 스택이 빌 때까지
        int v = stack[top--]; // pop

        if (!visited[v]) {   // 아직 방문하지 않은 정점이면
            printf("Visit %d\n", v);
            visited[v] = 1;

            // 인접한 정점들을 스택에 push
            // 스택이므로, 역순으로 넣으면 작은 번호부터 방문
            for (int i = g->numVertices - 1; i >= 0; i--) {
                if (g->adj[v][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}

// BFS: 큐를 이용한 너비 우선 탐색
void BFS(Graph *g, int start) {
    int visited[MAX_VERTICES] = {0}; // 방문 여부 배열
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    if (start < 0 || start >= g->numVertices) {
        printf("\n[BFS] 잘못된 시작 정점입니다.\n");
        return;
    }

    // 시작 정점을 큐에 enqueue
    queue[rear++] = start;

    printf("\n[BFS] Start from %d\n", start);

    while (front < rear) {   // 큐가 빌 때까지
        int v = queue[front++]; // dequeue

        if (!visited[v]) {   // 아직 방문하지 않은 정점이면
            printf("Visit %d\n", v);
            visited[v] = 1;

            // 인접한 정점들을 큐에 enqueue
            for (int i = 0; i < g->numVertices; i++) {
                if (g->adj[v][i] == 1 && !visited[i]) {
                    queue[rear++] = i;
                }
            }
        }
    }
}

// main 함수: 예시 그래프를 만들고 DFS, BFS를 실행해 보기
int main(void) {
    Graph g;

    // 간단한 예시: 정점 7개 (0 ~ 6)
    // 슬라이드의 도시 그래프와 비슷하게 구성했다고 가정
    initGraph(&g, 7);

    // 예시 간선들
    // 0 - 1 - 2 - 4 - 6
    //      \- 3
    // 2 - 5
    addEdge(&g, 0, 1); // 0-1
    addEdge(&g, 1, 2); // 1-2
    addEdge(&g, 1, 3); // 1-3
    addEdge(&g, 2, 4); // 2-4
    addEdge(&g, 2, 5); // 2-5
    addEdge(&g, 4, 6); // 4-6

    printf("===== Graph Traversal Practice (DFS / BFS) =====\n");
    printAdjMatrix(&g);

    // 시작 정점을 0으로 두고 DFS, BFS 실행
    DFS(&g, 0);
    BFS(&g, 0);

    printf("\nProgram finished.\n");
    return 0;
}
