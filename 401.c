#include <stdlib.h>
#include <stdio.h>
#include "itertools.h"
#include "myString.h"
#include "myStack.h"
struct element{
    void *item;
};
char** readBinaryWatch(int turnedOn, int* returnSize) {
    struct element b[10];
    for(int i=0; i<10; i++){
        int *x = (int *)malloc(sizeof(int));
        *x = i;
        b[i].item = (void *)x;
    }
    int returnSize1 = 0;
    int elementSize = sizeof(struct element);
    int maxSize = sizeof(b)/elementSize;
    struct element** x = (struct element**)myGenerateCombinations(maxSize, turnedOn, b, elementSize, &returnSize1);
    int time[10] = {8,4,2,1,32,16,8,4,2,1};
    char **ans = (char **)malloc(sizeof(char *)*returnSize1);
    int count = 0;
    for(int i=0; i<returnSize1; i++){
        int hour = 0;
        int minute = 0;
        int hourSize = 0;
        int minuteSize = 0;
        for(int j=0; j<turnedOn; j++){
            if(*(int *)x[i][j].item<4){
                hour+= time[*(int *)x[i][j].item];
            }else{
                minute += time[*(int *)x[i][j].item];
            }
        }
        if(minute<60&&hour<12){
            char *hour_c = intToChar(hour, &hourSize);
            char *minute_c = intToChar(minute, &minuteSize);
            char xxxx[] = ":";
            char *new = myStringCatch(hour_c,xxxx, NULL);
            if(minuteSize==1){
                char *new2 = (char *)malloc(sizeof(char)*3);
                new2[0] = '0';
                new2[1] = minute_c[0];
                new2[2] = minute_c[1];
                ans[count] = myStringCatch(new, new2, NULL);
                free(new2);
            }else{
                ans[count] = myStringCatch(new, minute_c, NULL);
            }
            count++;
            free(hour_c);
            free(minute_c);
            free(new);
            minute = 0;
            hour = 0;
        }
    }
    *returnSize = count;
    return ans;
}
int main(void) {
    int returnSize = 0;
    char **ans = readBinaryWatch(1, &returnSize);
    for(int i=0; i<returnSize; i++){
        printf("%s\n", ans[i]);
        free(ans[i]);
    }
    free(ans);
    return 0;
}
