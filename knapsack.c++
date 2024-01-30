#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};
class knapsack
{
public:
    static bool cmp(pair<double, Item> a, pair<double, Item> b)
    {
        return a.first > b.first;
    }
    double fractionalknapsack(int W, Item arr[], int n)
    {
        vector<pair<double, Item>> v;
        for (int i = 0; i < n; i++)
        {
            double perunitvalue = (1.0 * arr[i].value) / arr[i].weight;
            pair<double, Item> p = make_pair(perunitvalue, arr[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end(), cmp);
        cout << "value\t\tweight\t\tvalue/weight" << endl;
        for (auto i : v)
        {
            cout << i.second.value << "\t\t" << i.second.weight << "\t\t" << i.first << endl;
        }
        cout << endl;
        double totalvalue = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].second.weight > W)
            {
                totalvalue += W * v[i].first;
            }
            else
            {
                totalvalue += v[i].second.value;
                W = W - v[i].second.weight;
            }
        }
        cout << "maximum cost : ";
        return totalvalue;
    }
};

int main()
{
    Item arr[] = {{10, 2}, {5, 3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}};
    int n = 7;

    int W = 15;

    knapsack obj;
    cout << obj.fractionalknapsack(W, arr, n);

    return 0;
}
