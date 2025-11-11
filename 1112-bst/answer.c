#include <stdio.h>      // printf 함수 사용을 위해 포함
#include <stdlib.h>     // malloc, free, exit 사용을 위해 포함
#include "main.h"

/*----------------------------------------------------------
  탐색 함수: bst_search
  - 주어진 키(x)를 트리에서 찾아서 해당 노드 포인터를 반환
  - 존재하지 않으면 NULL 반환
  - 원리: BST는 '왼쪽 < 루트 < 오른쪽' 규칙을 이용
----------------------------------------------------------*/
Node* bst_search(Node* root, Key x) {
    Node* cur = root;                     // 탐색은 루트 노드부터 시작
    while (cur) {                         // NULL에 도달할 때까지 반복
        if (x == cur->NEED_TO_SOLVE) return NEED_TO_SOLVE;    // 키가 일치하면 탐색 성공 → 해당 노드 반환
        if (x < cur->key)                 // 찾는 값이 현재 키보다 작으면
            cur = cur->NEED_TO_SOLVE;              // ?쪽 서브트리로 이동
        else                              // 찾는 값이 현재 키보다 크면
            cur = cur->NEED_TO_SOLVE;             // ?쪽 서브트리로 이동
    }
    return NULL;                          // 루프 종료 시 NULL이면 해당 키는 트리에 없음
}

/*----------------------------------------------------------
  삽입 함수: bst_insert
  - 새로운 키(x)를 BST에 삽입하여 새로운 루트를 반환
  - 중복 키는 삽입하지 않고 무시함
  - 원리: 빈 자리를 찾을 때까지 내려가서 새 노드를 붙임
----------------------------------------------------------*/
Node* bst_insert(Node* root, Key x) {
    if (root == NULL) {                          // 트리가 비어 있으면
        Node* n = (Node*)malloc(sizeof(Node));   // 새 노드를 동적 할당
        if (!n) { perror("malloc"); exit(1); }   // 메모리 부족 시 오류 처리
        n->key = NEED_TO_SOLVE;                              // 새 노드에 키 저장
        n->left = n->right = NEED_TO_SOLVE;               // 처음에는 자식이 없음
        return n;                                // 새 노드가 곧 루트가 됨
    }

    Node* cur = root;                            // 현재 탐색 위치 (루트부터 시작)
    Node* parent = NEED_TO_SOLVE;                         // 부모 노드를 저장할 변수
    while (cur) {                                // NULL을 만날 때까지 반복
        parent = cur;                            // 현재 노드를 부모로 기억
        if (x == cur->key) return NEED_TO_SOLVE;          // 이미 존재하는 키이면 삽입하지 않음
        if (x < cur->key) cur = NEED_TO_SOLVE;       // 작으면 왼쪽으로
        else              cur = NEED_TO_SOLVE;      // 크면 오른쪽으로
    }

    Node* n = (Node*)malloc(sizeof(Node));       // 새 노드를 생성
    if (!n) { perror("malloc"); exit(1); }       // 메모리 오류 처리
    n->key = NEED_TO_SOLVE;                                  // 새 노드에 키 저장
    n->left = n->right = NEED_TO_SOLVE;                   // 새 노드는 리프로 시작

    if (x < parent->key) parent->left = NEED_TO_SOLVE;       // 삽입 위치가 부모보다 작으면 왼쪽에 연결
    else                 parent->right = NEED_TO_SOLVE;      // 크면 오른쪽에 연결

    return root;                                 // 루트는 그대로 반환
}

/*----------------------------------------------------------
  삭제 함수: bst_delete
  - 키(x)를 가진 노드를 트리에서 제거
  - 자식의 개수(0개, 1개, 2개)에 따라 세 가지로 분리
  - 원리: 후계자(successor) 노드로 키를 대체하여 구조 유지
----------------------------------------------------------*/
Node* bst_delete(Node* root, Key x) {
    if (root == NULL) return NULL;                 // 빈 트리면 바로 반환

    if (x < root->key) {                           // 삭제할 키가 루트보다 작으면
        root->left = NEED_TO_SOLVE(root->left, x);    // 왼쪽 서브트리에서 삭제 후 연결
        return root;                               // 전체 루트는 그대로 유지
    }

    if (x > root->key) {                           // 삭제할 키가 루트보다 크면
        NEED_TO_SOLVE;                              // 오른쪽 서브트리에서 삭제 후 연결
        return root;                               // 전체 루트는 그대로 유지
    }

    // 이 시점에서 x == root->key, 즉 삭제할 노드를 찾음
    if (root->left == NULL && root->right == NULL) { // (1) 자식이 없는 리프 노드
        free(NEED_TO_SOLVE);                                 // 그냥 메모리 해제
        return NEED_TO_SOLVE;                                // 부모에서 이 자리는 NULL로 대체됨
    }

    if (root->left == NULL || root->right == NULL) { // (2) 자식이 1개인 경우
        Node* child = (root->left) ? root->left : root->right; // 존재하는 자식을 선택
        free(root);                                 // 현재 노드를 해제
        return child;                               // 자식을 부모에게 반환(직접 연결)
    }

    // (3) 자식이 2개인 경우 - 오른쪽 서브트리에서 가장 작은 키(후계자)를 찾아 키를 대체
    Node* succ = NEED_TO_SOLVE;                      // 오른쪽 서브트리의 루트로 시작
    while (succ->left) succ = NEED_TO_SOLVE;          // 왼쪽으로 계속 내려가 최소값 찾기
    root->key = succ->key;                         // 현재 노드의 키를 후계자의 키로 변경
    root->right = NEED_TO_SOLVE(root->right, NEED_TO_SOLVE); // 오른쪽 서브트리에서 후계자 삭제
    return root;                                   // 루트 반환 (구조 유지)
}

/*----------------------------------------------------------
  중위 순회 함수: bst_inorder
  - 왼쪽 → 루트 → 오른쪽 순서로 방문
  - BST에서는 항상 오름차순으로 출력됨
----------------------------------------------------------*/
void bst_inorder(Node* root) {
    if (!root) return;               // 공(空) 노드이면 종료
    bst_inorder(root->left);         // 왼쪽 서브트리 먼저 출력
    printf("%d ", root->key);        // 현재 노드의 키 출력
    bst_inorder(root->right);        // 오른쪽 서브트리 출력
}

/*----------------------------------------------------------
  메모리 해제 함수: bst_free
  - 후위 순회(Post-order) 방식으로 모든 노드를 해제
  - 자식부터 해제해야 부모를 안전하게 제거 가능
----------------------------------------------------------*/
void bst_free(Node* root) {
    if (!root) return;               // NULL이면 아무 작업도 안 함
    bst_free(root->left);            // 왼쪽 자식 해제
    bst_free(root->right);           // 오른쪽 자식 해제
    free(root);                      // 마지막에 자기 자신 해제
}