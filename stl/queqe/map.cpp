#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> m;
    m[2] = "shiva";
    m[23] = "anu";
    m[5] = "kanaujiya";
    m.insert({6, "naresh"});
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    m.erase(6);
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    //  m.count
    auto it = m.find(5);
    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << endl;
    }
    return 0;
}