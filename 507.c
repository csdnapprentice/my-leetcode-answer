#include "myMath.h"
#include <stdio.h>
#include <stdbool.h>
bool checkPerfectNumber(int num) {
    int sum = 0;
    double sqrt = mySqrt(num);
    if(num>=2) {
        for (int i = 1; i <= sqrt; i++) {
            double z = 1.0 * num / i;
            if ((int) z == z) {
                sum += i;
                if (z != i && z != num) {
                    sum += z;
                }
            }
        }
        if (sum == num) {
            return true;
        }
    }
    return false;
}
int main(){
    printf("%d", checkPerfectNumber(28));
    return 0;
}
