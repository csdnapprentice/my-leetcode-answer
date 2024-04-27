#include <stdlib.h>
#include <stdio.h>
char *myStringCopy(char *s){
    int i = 0;
    while(s[i]!='\0'){
        i++;
    }
    char *ans = (char *)malloc(sizeof(char)*(i+1));
    i = 0;
    for(; s[i]!='\0'; i++){
        ans[i] = s[i];
    }
    ans[i] = '\0';
    return ans;
}
char * intToChar(int num, int *returnSize){
    int length = 0;
    int n = num;
    char *ans = NULL;
    while(n!=0){
        n /= 10;
        length++;
    }
    if(num>0) {
        ans = (char *) malloc(sizeof(char) * (length + 1));
        n = num;
    }else if(num==0){
        ans = (char *)malloc(sizeof(char)*2);
        ans[0] = '0';
        ans[1] = '\0';
        *returnSize = 1;
        return ans;
    }else{
        ans = (char *)malloc(sizeof(char)*(length+2));
        length += 1;
        n = num;
    }
    if(returnSize != NULL) {
        *returnSize = length;
    }
    ans[length--] = '\0';
    for(; n != 0; n/=10){
        ans[length--] = (char)(n%10>0?n%10:-1*(n%10))+'0';
    }
    if(num<0){
        ans[0] = '-';
    }
    return ans;
}
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    int *rank = (int *)malloc(sizeof(int)*scoreSize);
    int max = score[0];
    int maxIndex = 0;
    for(int i=0; i<scoreSize; i++){
        if(max<score[i]){
            max = score[i];
            maxIndex = i;
        }
    }
    rank[0] = maxIndex;
    maxIndex = -1;
    max = -1;
    for(int i=1; i<scoreSize; i++){
        for(int j=0; j<scoreSize; j++){
            if(max<score[j]&&score[rank[i-1]]>score[j]){
                max = score[j];
                maxIndex = j;
            }
        }
        rank[i] = maxIndex;
        maxIndex = -1;
        max = -1;
    }
    char ** ans = (char **)malloc(sizeof(char *)*scoreSize);
    *returnSize = scoreSize;
    char x1[] = "Gold Medal";
    char x2[] = "Silver Medal";
    char x3[] = "Bronze Medal";
    for(int i=0; i<scoreSize; i++){
        if(i==0){
            ans[rank[i]] = myStringCopy(x1);
        }else if( i == 1){
            ans[rank[i]] = myStringCopy(x2);
        }else if(i == 2){
            ans[rank[i]] = myStringCopy(x3);
        }
        else{
            ans[rank[i]] = intToChar(i+1, NULL);
        }
    }
    free(rank);
    rank = NULL;
    return ans;
}
int main(){
    int score[] = {5,4,3,2,1};
    int returnSize = 0;
    char **ans = findRelativeRanks(score, 5, &returnSize);
    for(int i=0; i<returnSize; i++){
        printf("%s", ans[i]);
    }
    return 0;
}