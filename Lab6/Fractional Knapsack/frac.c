#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
    float ratio;
} Item;

int cmp(const void* a, const void* b) {
    float r1 = ((Item*)a)->ratio;
    float r2 = ((Item*)b)->ratio;
    return (r2 > r1) - (r2 < r1);
}

int main() {
    int n;
    float capacity, total = 0.0;
    printf("Enter number of items and knapsack capacity: ");
    scanf("%d %f", &n, &capacity);

    Item items[n];
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    qsort(items, n, sizeof(Item), cmp);

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            total += items[i].value;
        } else {
            total += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", total);
    return 0;
}
