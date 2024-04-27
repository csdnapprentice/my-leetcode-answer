#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode{
    int val;
    struct ListNode * next;
};
bool isPalindrome(struct ListNode* head) {
    struct ListNode *p = NULL;
    struct ListNode *q = head;
    int count1 = 0;
    while(q != NULL){
        struct ListNode *z = (struct ListNode *)malloc(sizeof(struct ListNode));
        z->val = q->val;
        z->next = p;
        p = z;
        q = q->next;
        count1++;
    }
    q = head;
    int flag = 1;
    int count2 = 0;
    while(p!=NULL){
        if(q->val != p->val){
            flag = 0;
            break;
        }
        if(count2==count1/2){
            break;
        }
        q = q->next;
        p = p->next;
        count2++;
    }
    if(flag){
        return true;
    }
    return false;
}
int main(){
    struct ListNode *head = NULL;
    for(int i=0; i<5; i++){
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = i;
        p->next = head;
        head = p;
    }
    isPalindrome(head);
    return 0;
}