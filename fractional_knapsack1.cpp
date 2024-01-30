#include <iostream>
#include <vector>
#include <algorithm>

struct Item
{
    int object;
    double profit;
    double weight;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

std::pair<double, std::vector<int>> fractional_knapsack(double capacity, std::vector<double> profits, std::vector<double> weights, std::vector<int> objects)
{
    int n = profits.size();
    std::vector<Item> items(n);

    for (int i = 0; i < n; ++i)
    {
        items[i].object = objects[i];
        items[i].profit = profits[i];
        items[i].weight = weights[i];
        items[i].ratio = profits[i] / weights[i];
    }

    std::sort(items.begin(), items.end(), compare);

    double total_profit = 0;
    std::vector<int> selected_items;

    for (int i = 0; i < n; ++i)
    {
        if (items[i].weight <= capacity)
        {
            total_profit += items[i].profit;
            capacity -= items[i].weight;
            selected_items.push_back(items[i].object);
        }
        else
        {
            double fraction = capacity / items[i].weight;
            total_profit += items[i].profit * fraction;
            selected_items.push_back(items[i].object);
            break;
        }
    }

    return std::make_pair(total_profit, selected_items);
}

int main()
{

    double knapsack_capacity = 15;
    std::vector<int> objects = {1, 2, 3, 4, 5, 6, 7};
    std::vector<double> profits = {10, 5, 15, 7, 6, 18, 3};
    std::vector<double> weights = {2, 3, 5, 7, 1, 4, 1};

    auto result = fractional_knapsack(knapsack_capacity, profits, weights, objects);
    double max_profit = result.first;
    std::vector<int> selected_objects = result.second;

    std::cout << "1) Profit/Weight Ratio:" << std::endl;
    for (size_t i = 0; i < objects.size(); ++i)
    {
        double ratio = profits[i] / weights[i];
        std::cout << "Object " << objects[i] << ": " << ratio << std::endl;
    }

    std::cout << "\n2) Objects to be placed inside the bag:" << std::endl;
    for (int object : selected_objects)
    {
        std::cout << "Object " << object << std::endl;
    }

    std::cout << "\n3) The total maximum profit: " << max_profit << std::endl;

    return 0;
}
