// Rishabh Ranjan 25/DA/054

#include <iostream>

using namespace std;

struct Item {
    int value;
    int weight;
};

void swapItems(Item& a, Item& b) {
    Item temp = a;
    a = b;
    b = temp;
}

void sortItemsByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                swapItems(items[j], items[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(int W, Item items[], int n) {
    sortItemsByRatio(items, n);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = W - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 50;
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items, n) << endl;

    return 0;
}
