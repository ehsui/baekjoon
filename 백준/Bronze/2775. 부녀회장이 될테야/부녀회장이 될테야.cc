#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int T, k, n, before[14], after[14], floor=0;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &k);//k층
        scanf("%d", &n);//n호

        for (int j = 0; j < 14; j++) {
            before[j] = j+1;
        }//0층짜리 만들기

        after[0] = 1;
        for (int q = 0; q < k; q++) {
            for (int j = 1; j < 14; j++) {
                after[j] = after[j - 1] + before[j];
            }
            for (int j = 1; j < 14; j++) {
                before[j] = after[j];
            }
        }
        printf("%d\n", before[n-1]);
    }
    
    return 0;
} 