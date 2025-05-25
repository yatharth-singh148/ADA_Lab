#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

int mobile(int a[], int dir[], int n) {
    int max = 0, mob = 0;
    for (int i = 0; i < n; i++) {
        int next = i + dir[i];
        if (next >= 0 && next < n && a[i] > a[next] && a[i] > max) {
            max = a[i];
            mob = i;
        }
    }
    return mob;
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter(int n) {
    int a[n], dir[n];
    for (int i = 0; i < n; i++) { a[i] = i + 1; dir[i] = LEFT; }

    print(a, n);

    while (1) {
        int m = mobile(a, dir, n);
        if (m == 0 && a[m] <= a[m + dir[m]]) break;

        int swapIdx = m + dir[m];
        int temp = a[m]; a[m] = a[swapIdx]; a[swapIdx] = temp;
        temp = dir[m]; dir[m] = dir[swapIdx]; dir[swapIdx] = temp;

        for (int i = 0; i < n; i++)
            if (a[i] > a[swapIdx]) dir[i] *= -1;

        print(a, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
