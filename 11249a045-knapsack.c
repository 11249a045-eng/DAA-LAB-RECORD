#include <stdio.h>
struct Item {
    int profit;
    int weight;
    float ratio;
};
int main() {
    int n, capacity;
    float totalProfit = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item item[n];
    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    printf("\nItems selected:\n");
    for (int i = 0; i < n; i++) {
        if (capacity >= item[i].weight) {
            printf("Item with profit %d and weight %d taken fully\n",
                   item[i].profit, item[i].weight);
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else {
            printf("Item with profit %d and weight %d taken partially\n",
                   item[i].profit, item[i].weight);
            totalProfit += item[i].profit * ((float)capacity / item[i].weight);
            break;
        }
    }
    printf("\nMaximum Profit = %.2f\n", totalProfit);
    return 0;
}

