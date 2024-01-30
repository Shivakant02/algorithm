#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(8);
    v.push_back(5);
    v.push_back(6);
    v.push_back(4);
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "finding 7->" << binary_search(v.begin(), v.end(), 7) << endl;
    cout << "lower bound:" << lower_bound(v.begin(), v.end(), 7) - v.begin() << endl;
    cout << "upper bound:" << upper_bound(v.begin(), v.end(), 8) - v.begin() << endl;
    int a = 4, b = 7;
    swap(a, b);
    cout << a << endl;
    string c = "asdf";
    reverse(c.begin(), c.end());
    cout << c << endl;
    sort(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}