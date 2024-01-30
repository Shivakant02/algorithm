#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    cout << "capacity->" << v.capacity() << endl;
    v.push_back(1);
    cout << "capacity->" << v.capacity() << endl;
    v.push_back(2);
    cout << "capacity->" << v.capacity() << endl;
    v.push_back(3);
    cout << "capacity->" << v.capacity() << endl;
    cout << "size->" << v.size() << endl;
    // other operations
    // v.at(2);,front,back
    cout << "capacity->" << v.capacity() << endl;
    v.pop_back();
    cout << "size->" << v.size() << endl;
    cout << "capacity->" << v.capacity() << endl;
    v.clear();
    cout << "size->" << v.size() << endl;
    cout << "capacity->" << v.capacity() << endl;
    vector<int> a(5, 1);

    for (int i : a)
        cout << i << " ";
    return 0;
}