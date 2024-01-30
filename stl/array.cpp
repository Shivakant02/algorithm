#include <bits/stdc++.h>
using namespace std;

int main()
{
    array<int, 4> a = {1, 2, 3, 4};
    cout << "size->" << a.size() << endl;
    cout << "element at 2nd index :" << a.at(2) << endl;
    cout << "is empty" << a.empty() << endl;
    cout << a.front() << a.back();
    return 0;
}