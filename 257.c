#include <stdio.h>
#include "myArray.h"
#include "myStack.h"
#include "myString.h"
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/*
 * Written by HengYuan Hu on April 24, 2024.
 * This function converts a binary tree into a string representing the path to each leaf node.
 * The time complexity depends on the depth of the binaryTree.and it is related to the number of nodes.
 * construct the path string will spend some time but this will not too much.
 * The time complexity is about O(n);
 */
char * solve(struct TreeNode *root, int * returnSize, char *x, char **ans){
    char *new1 = "->";
    char * new = myStringCatch(x, new1, NULL);
    free(x);
    char *num = intToChar(root->val, NULL);
    x = myStringCatch(new, num, NULL);
    free(new);
    free(num);
    new = NULL;
    num = NULL;
    if(root->left == NULL&&root->right == NULL){
        ans[*returnSize] = myStringCopy(x);
        *returnSize = *returnSize + 1;
    }
    if(root->left != NULL){
        x = solve(root->left, returnSize, x, ans);
        myStringRemoveSubSequence(x, "->");
    }
    if(root->right != NULL){
        x = solve(root->right, returnSize, x, ans);
        myStringRemoveSubSequence(x, "->");
    }
    return x;
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char **ans = (char **)malloc(sizeof(char *)*100);
    char *x = NULL;
    *returnSize = 0;
    x = intToChar(root->val, NULL);
    if(root->left == NULL&&root->right==NULL){
        ans[*returnSize] = x;
        *returnSize = *returnSize + 1;
    }
    if(root->left != NULL){
        x = solve(root->left, returnSize, x, ans);
        myStringRemoveSubSequence(x, "->");
    }
    if(root->right != NULL){
        x = solve(root->right, returnSize, x, ans);
        myStringRemoveSubSequence(x, "->");
    }
    return ans;
}
int main(void) {
    struct TreeNode * root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->left->right = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->left->right->val = 6;
    root->left->left = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->left->left->val = 5;
    root->right->left = NULL;
    root->right->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    int returnSize = 0;
    char **ans = binaryTreePaths(root, &returnSize);
    for(int i = 0; i< returnSize; i++){
        printf("%s\n",ans[i]);
        free(ans[i]);
    }
    free(ans);
    return 0;
}

