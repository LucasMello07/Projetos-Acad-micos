#pragma once

typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
    int rank;
    int level;
} BSTNode;

typedef struct BST {
    BSTNode* root;
    int size;
} BST;

BST* newBST();
void bstPut( BST* abb, int key );
BSTNode* bstPutR( BSTNode* node, int key );

void bstPreOrder( BSTNode* node );
void bstInOrder( BSTNode* node );
void bstPostOrder( BSTNode* node );

void bstProcess( BSTNode* node, int* currentRank, int level, int *maxLevel );
void bstDraw( BST *bst );

void bstPrintNode( BSTNode *node );