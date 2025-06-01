#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

// Compare function to sort items by profit/weight ratio (descending)
int compare(const void* a, const void* b) {
    Item* i1 = (Item*)a;
    Item* i2 = (Item*)b;
    if (i1->ratio < i2->ratio) return 1;
    else if (i1->ratio > i2->ratio) return -1;
    else return 0;
}

void fractionalKnapsack(Item items[], int n, int capacity) {
    int i;
    float totalProfit = 0.0;

    // Sort items by ratio
    qsort(items, n, sizeof(Item), compare);

    printf("Item\tWeight\tProfit\tTaken\n");

    for (i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // Take whole item
            printf("%d\t%d\t%d\t%.2f\n", i+1, items[i].weight, items[i].profit, 1.0);
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            // Take fraction of item
            float fraction = (float)capacity / items[i].weight;
            printf("%d\t%d\t%d\t%.2f\n", i+1, items[i].weight, items[i].profit, fraction);
            totalProfit += items[i].profit * fraction;
            capacity = 0;
        }
    }

    printf("Total Profit: %.2f\n", totalProfit);
}

int main() {
    int n = 3; // number of items
    int capacity = 50;

    Item items[] = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };

    // Calculate ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    fractionalKnapsack(items, n, capacity);

    return 0;
}
