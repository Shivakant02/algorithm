#include <iostream>
#include <vector>
#include <algorithm>

struct Object
{
    int index;
    double profit;
    double weight;
    double ratio;
};

bool compare(Object a, Object b)
{
    return a.ratio > b.ratio;
}

std::pair<double, std::vector<int>> fractional_knapsack(std::vector<double> &profits, std::vector<double> &weights, double capacity)
{
    int n = profits.size();
    std::vector<Object> objects(n);
    std::vector<int> selected_objects;

    // Calculate profit/weight ratio for each object
    for (int i = 0; i < n; i++)
    {
        objects[i].index = i;
        objects[i].profit = profits[i];
        objects[i].weight = weights[i];
        objects[i].ratio = profits[i] / weights[i];
    }

    std::sort(objects.begin(), objects.end(), compare);

    double total_profit = 0.0;

    for (const auto &object : objects)
    {
        if (capacity == 0)
            break;

        int index = object.index;
        double weight = object.weight;

        if (weight <= capacity)
        {
            // Take the whole object
            total_profit += profits[index];
            capacity -= weight;
            selected_objects.push_back(index);
        }
        else
        {
            // Take a fraction of the object
            double fraction = capacity / weight;
            total_profit += profits[index] * fraction;
            capacity = 0;
            selected_objects.push_back(index);
        }
    }

    return {total_profit, selected_objects};
}

int main()
{
    std::vector<double> profits = {5, 10, 15, 7, 8, 9, 4};
    std::vector<double> weights = {1, 3, 5, 4, 1, 3, 2};
    double knapsack_capacity = 15;

    auto result = fractional_knapsack(profits, weights, knapsack_capacity);
    double max_profit = result.first;
    std::vector<int> selected_items = result.second;

    // Print the results
    std::cout << "Profit/Weight Ratio:\n";
    std::vector<Object> objects(profits.size());
    for (int i = 0; i < profits.size(); i++)
    {
        objects[i].index = i;
        objects[i].profit = profits[i];
        objects[i].weight = weights[i];
        objects[i].ratio = profits[i] / weights[i];
    }
    std::sort(objects.begin(), objects.end(), compare);
    for (const auto &object : objects)
    {
        std::cout << "Object " << object.index + 1 << ": " << object.ratio << "\n";
    }

    std::cout << "\nObjects to be placed inside the bag:\n";
    for (int index : selected_items)
    {
        std::cout << "Object " << index + 1 << "\n";
    }

    std::cout << "\nTotal Maximum Profit: " << max_profit << "\n";

    return 0;
}
