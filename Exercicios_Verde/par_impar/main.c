#include <stdio.h>

int main (void) {
    int n = 0;
    int x = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (x%2==0) {
            printf("PAR\n");
        } else {
            printf("IMPAR\n");
        }
    }

    return 0;
}
