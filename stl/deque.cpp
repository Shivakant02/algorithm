#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d;
    d.push_back(3);
    d.push_back(2);
    d.push_front(5);
    d.push_front(7);
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    d.pop_back();
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "size->" << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);
    cout << "size->" << d.size() << endl;

    return 0;
}