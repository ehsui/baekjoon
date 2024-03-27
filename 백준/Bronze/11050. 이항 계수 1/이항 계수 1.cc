#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int N, K, a = 1, b = 1;

    scanf("%d %d", &N, &K);

    for (int i = 1; i <= K; i++) {
        a *= (N + 1) - i;
        b *= i;
    } 
    printf("%d", a / b);
    return 0;
} 