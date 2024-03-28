#include <stdio.h>
#define M 1234567891

int main(void) {
    int L;
    long long index = 0, Q = 0, r = 1;
    char ary[51] = { 0 };

    scanf("%d", &L);

    for (int i = 0; i < L; i++) {
        scanf(" %c", &ary[i]);
        ary[i] -= 96;
    }
    
    for (int i = 0; i < L; i++) {
        r = 1;
        for (int j = 0; j < i; j++) {
            r *= 31;
            r %= M;
        }
        Q += ary[i] * r % M;
    }

    printf("%lld", Q%M);

    return 0;
}