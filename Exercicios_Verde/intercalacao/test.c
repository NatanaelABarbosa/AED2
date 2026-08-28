#include <stdio.h>

int binSearch(int * arr, int n, int x, int esq, int dir) {
    if (esq>dir) return -1;
    else {
        int meio = (esq+dir)/2;
        if (arr[meio] == x) {
            return meio;
        } else if (x > arr[meio]) {
            return binSearch(arr, n, x, meio+1, dir);
        } else {
            return binSearch(arr, n, x, esq, meio-1);
        }
    }

}

int main (void) {
    int n = 10;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = i+1;
    int x = 8;

    printf("%d\n", binSearch(arr, n, x, 0, n-1));

    return 0;
}
