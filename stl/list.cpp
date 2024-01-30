#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(3);
    l.push_front(5);
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "size->" << l.size();
    // pop,erase,empty etc here............
    return 0;
}
