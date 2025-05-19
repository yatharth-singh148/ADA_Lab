#include <stdio.h>
#include <stdlib.h>

void findSubsets(int *arr, int n, int target, int *subset, int subsetSize, int currentIndex) {
    int currentSum = 0;
    for (int i = 0; i < subsetSize; i++) {
        currentSum += subset[i];
    }
    
    if (currentSum == target) {
        printf("{ ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }
    

    if (currentIndex >= n) {
        return;
    }
    subset[subsetSize] = arr[currentIndex];
    findSubsets(arr, n, target, subset, subsetSize + 1, currentIndex + 1);
    findSubsets(arr, n, target, subset, subsetSize, currentIndex + 1);
}

int main() {
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the target sum: ");
    scanf("%d", &target);
    int *subset = (int *)malloc(n * sizeof(int));

    printf("Subsets with sum %d:\n", target);
    findSubsets(arr, n, target, subset, 0, 0);
    free(subset);

    return 0;
}
