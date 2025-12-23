#ifndef CLASSIFICATION_TREE_H
#define CLASSIFICATION_TREE_H

#define MAX_LABEL 20

typedef struct TreeNode {
    char label[MAX_LABEL];
    int min_fail;
    int max_fail;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Fonctions
TreeNode* createNode(const char *label, int min, int max);
TreeNode* buildClassificationTree();
const char* classifyUser(TreeNode *root, int fail_count);
void freeTree(TreeNode *root);

#endif
