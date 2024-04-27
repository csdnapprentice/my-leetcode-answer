#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int* middleOrderTraversal(struct TreeNode* root, int* returnSize) {
    if(root!=NULL){
        int *left = middleOrderTraversal(root->left, returnSize);
        int leftLength = *returnSize;
        int *right = middleOrderTraversal(root->right, returnSize);
        int rightLength = *returnSize;
        int num = leftLength + rightLength;
        int *answer = (int *)malloc(sizeof(int)*(num+1));
        int k = 0;
        for(int i=0; i<leftLength; i++){
            answer[k++] = left[i];
        }
        answer[k++] = root->val;
        for(int i=0; i<rightLength; i++){
            answer[k++] = right[i];
        }
        free(left);
        free(right);
        left = NULL;
        right = NULL;
        *returnSize = num+1;
        return answer;
    }
    *returnSize = 0;
    return NULL;
}
int* findMode(struct TreeNode* root, int* returnSize) {
    int length = 0;
    int *x = middleOrderTraversal(root, &length);
    int *max = (int *)malloc(sizeof(int)*length);
    *returnSize = 0;
    int maxCount = 0;
    int now = __INT_MAX__;
    int nowCount = 0;
    int i = 0;
    for(; i<length; i++){
        if(x[i] == now){
            nowCount++;
        }else{
            if(nowCount==maxCount){
                max[*returnSize] = now;
                *returnSize = *returnSize + 1;
            }else if(nowCount>maxCount){
                *returnSize = 0;
                max[*returnSize] = now;
                maxCount = nowCount;
                *returnSize = *returnSize + 1;
            }
            now = x[i];
            nowCount = 1;
        }
    }
    if(nowCount==maxCount){
        max[*returnSize] = now;
        *returnSize = *returnSize + 1;
    }else if(nowCount>maxCount){
        *returnSize = 0;
        max[*returnSize] = now;
        *returnSize = *returnSize + 1;
    }
    free(x);
    x= NULL;
    return max;
}
int main(){
    struct TreeNode * root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = 2;
    root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->left->val = 2;
    root->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    int length = 0;
    int *x = findMode(root,&length);
    for(int i=0; i< length; i++){
        printf("%d", x[i]);
    }
    return 0;
}