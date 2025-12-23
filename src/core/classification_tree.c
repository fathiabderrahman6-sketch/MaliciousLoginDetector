#include <stdlib.h>
#include <string.h>
#include "classification_tree.h"

// Créer un noeud
TreeNode* createNode(const char *label, int min, int max) {
    TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
    strcpy(n->label, label);
    n->min_fail = min;
    n->max_fail = max;
    n->left = n->right = NULL;
    return n;
}

// Construire l'arbre de décision
TreeNode* buildClassificationTree() {
    TreeNode *normal = createNode("Normal", 0, 1);
    TreeNode *suspicious = createNode("Suspicious", 2, 3);
    TreeNode *attack = createNode("Attack", 4, 100);

    suspicious->left = normal;
    suspicious->right = attack;

    return suspicious; // racine
}

// Classifier un utilisateur
const char* classifyUser(TreeNode *root, int fail_count) {
    if (!root) return "Unknown";

    if (fail_count >= root->min_fail && fail_count <= root->max_fail)
        return root->label;

    if (fail_count < root->min_fail)
        return classifyUser(root->left, fail_count);
    else
        return classifyUser(root->right, fail_count);
}

// Libération mémoire
void freeTree(TreeNode *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
