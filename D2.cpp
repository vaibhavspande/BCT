#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
    double valuePerWeight;
};

bool compareItems(const Item &item1, const Item &item2)
{
    return item1.valuePerWeight > item2.valuePerWeight;
}

void fractionalKnapsack(int capacity, vector<Item> &items)
{

    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currrentWeight = 0;

    cout << "Fractions of items selected: " << endl;

    for (const Item &item : items)
    {
        if (currrentWeight + item.weight <= capacity)
        {
            cout << "Item " << item.weight << " kg     (Fraction = 1)" << endl;
            totalValue += item.value;
            currrentWeight += item.weight;
        }
        else
        {
            double fraction = static_cast<double>(capacity - currrentWeight) / item.weight;
            cout << "Item " << item.weight << " kg (Fraction = " << fraction << ")" << endl;
            totalValue += fraction * item.value;
            break;
        }
    }
    cout << "Maximum value in the knapsack: " << totalValue << endl;
}

int main()
{

    int capacity;
    cout << "Enter the maximum knapsack capacity: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter the weight and value of each item: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ":" << endl;
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
        items[i].valuePerWeight = static_cast<double>(items[i].value) / items[i].weight;
    }

    auto start = chrono::steady_clock::now();

    fractionalKnapsack(capacity, items);

    auto stop = chrono::steady_clock::now();

    size_t spaceComplexity = sizeof(int) * 2 + sizeof(double) * 2 + sizeof(vector<Item>) + sizeof(Item) * n;
    cout << "Space Complexity: " << spaceComplexity << " bytes " << endl;
    cout << "Time Complexity: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " microseconds" << endl;

    return 0;
}