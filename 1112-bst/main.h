// main.h
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int Key;

typedef struct Node {
    Key key;
    struct Node* left;
    struct Node* right;
} Node;

Node* bst_search(Node* root, Key x);
Node* bst_insert(Node* root, Key x);
Node* bst_delete(Node* root, Key x);

// 헬퍼(테스트/디버그용)
Node* new_node(Key x);
void   bst_inorder(Node* root);
void   bst_free(Node* root);
