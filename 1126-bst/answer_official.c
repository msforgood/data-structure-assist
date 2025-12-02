#include <stdio.h>
#include <stdlib.h>

// 트리의 노드를 표현하는 구조체 정의
struct Node {
    int key;               // 노드가 저장할 값 (정수)
    struct Node *left;     // 왼쪽 자식 노드에 대한 포인터
    struct Node *right;    // 오른쪽 자식 노드에 대한 포인터
};

// 새로운 노드를 생성하는 함수 (메모리 할당 포함)
struct Node* create_node(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {                     // 메모리 할당 실패 시 확인
        printf("Memory allocation error\n"); // 오류 메시지 출력
        exit(1);                             // 프로그램 강제 종료
    }
    node->key = key;    // 노드의 key 필드에 값 저장
    node->left = NULL;  // 초기 상태에서는 자식 노드 없음
    node->right = NULL; // 초기 상태에서는 자식 노드 없음
    return node;        // 생성한 노드의 주소를 반환
}

// BST 규칙에 따라 새로운 key를 삽입하는 함수
struct Node* insert(struct Node *root, int key) {
    if (root == NULL) {             // 현재 위치가 비어 있으면
        return create_node(key);    // 새로운 노드를 만들고 반환
    }
    if (key < root->key) {                  // 삽입하려는 값이 현재 노드보다 작으면
        root->left = insert(root->left, key); // 왼쪽 서브트리에 삽입
    } else if (key > root->key) {           // 삽입하려는 값이 현재 노드보다 크면
        root->right = insert(root->right, key); // 오른쪽 서브트리에 삽입
    }
    // key == root->key 인 경우: 중복은 무시하고 그대로 root 반환
    return root;   // 변경된 root를 그대로 반환
}

// 전위 순회: (현재 노드) → (왼쪽) → (오른쪽)
void preorder(struct Node *root) {
    if (root == NULL) { // 빈 노드(NULL)에 도달하면 즉시 종료
        return;
    }
    printf("%d ", root->key); // 현재 노드 방문: key 출력
    preorder(root->left);     // 왼쪽 서브트리 재귀 호출
    preorder(root->right);    // 오른쪽 서브트리 재귀 호출
}

// 중위 순회: (왼쪽) → (현재 노드) → (오른쪽)
void inorder(struct Node *root) {
    if (root == NULL) { // 빈 노드이면 종료
        return;
    }
    inorder(root->left);      // 왼쪽 서브트리를 먼저 방문
    printf("%d ", root->key); // 현재 노드 방문
    inorder(root->right);     // 오른쪽 서브트리 방문
}

// 후위 순회: (왼쪽) → (오른쪽) → (현재 노드)
void postorder(struct Node *root) {
    if (root == NULL) { // 빈 노드이면 종료
        return;
    }
    postorder(root->left);    // 왼쪽 서브트리 방문
    postorder(root->right);   // 오른쪽 서브트리 방문
    printf("%d ", root->key); // 마지막에 현재 노드 방문
}

// 트리 전체를 후위 순회 방식으로 메모리 해제하는 함수
void free_tree(struct Node *root) {
    if (root == NULL) { // NULL이면 할 일 없음
        return;
    }
    free_tree(root->left);   // 왼쪽 서브트리 해제
    free_tree(root->right);  // 오른쪽 서브트리 해제
    free(root);              // 마지막으로 현재 노드 해제
}

int main(void) {
    int n;                   // 입력받을 정수 개수를 저장할 변수
    struct Node *root = NULL; // BST의 루트 노드 (초기에는 비어 있음)

    printf("Enter number of integers: ");

    if (scanf("%d", &n) != 1) { // 정수 하나 입력받기 (개수)
        printf("Input error\n"); // 입력 실패 시 에러 출력
        return 1;                // 비정상 종료
    }

    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++) { // n개의 정수를 반복 입력
        int x;                    // 입력받을 정수를 저장
        if (scanf("%d", &x) != 1) { // 정수 입력 실패 검사
            printf("Input error\n");
            return 1;
        }
        root = insert(root, x); // 입력된 정수를 BST에 삽입
    }

    printf("Preorder: "); // 전위 순회 출력 안내
    preorder(root);       // 전위 순회 실행
    printf("\n");         // 줄바꿈

    printf("Inorder: ");  // 중위 순회 출력 안내
    inorder(root);        // 중위 순회 실행
    printf("\n");

    printf("Postorder: "); // 후위 순회 출력 안내
    postorder(root);       // 후위 순회 실행
    printf("\n");

    free_tree(root); // 동적 할당된 트리 메모리 해제
    return 0;        // 프로그램 정상 종료
}
