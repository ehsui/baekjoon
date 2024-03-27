#include <stdio.h>

int main(void) {
    int A, B, m, M;
    long long x, y;

    scanf("%d %d", &A, &B);

    if (A > B) {
        x = A;
        y = B;
    }
    else {
        x = B;
        y = A;
    }

    for (int i = y; i > 0; i--) {
        if ((A % i) == 0 && (B % i) == 0) {
            M = i;
            break;
        }
    }//최대공약수

    for (int i = x;; i++) {
        if ((i%A) == 0 && (i% B== 0)) {
            m = i;
            break;  
        }
    }

    printf("%d\n%d", M, m);
    return 0;
}