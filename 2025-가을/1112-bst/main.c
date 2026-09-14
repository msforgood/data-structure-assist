// main.c
#include "main.h"

int main(void){
    Node* root = NULL;

    // 삽입
    int vals[] = { 50, 30, 70, 20, 40, 60, 80 };
    for(size_t i=0;i<sizeof(vals)/sizeof(vals[0]);++i)
        root = bst_insert(root, vals[i]);

    printf("중위순회(오름차순): ");
    bst_inorder(root); puts("");

    // 검색
    int q[] = {40, 25, 80};
    for(int i=0;i<3;i++){
        Node* found = bst_search(root, q[i]);
        printf("search %d -> %s\n", q[i], found ? "found" : "not found");
    }

    // 삭제: 자식 0, 1, 2 케이스 차례로
    root = bst_delete(root, 20);  // leaf
    root = bst_delete(root, 30);  // one-child
    root = bst_delete(root, 50);  // two-children (root)

    printf("삭제 후 중위순회: ");
    bst_inorder(root); puts("");

    bst_free(root);
    return 0;
}
