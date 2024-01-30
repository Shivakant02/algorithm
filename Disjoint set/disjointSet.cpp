#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    // path compression
    int findUpath(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpath(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUpath(u);
        int ulp_v = findUpath(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    // union by size is more explainable
    void unionBySize(int u, int v)
    {
        int ulp_u = findUpath(u);
        int ulp_v = findUpath(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    if (ds.findUpath(3) == ds.findUpath(7))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }
    ds.unionBySize(3, 7);

    if (ds.findUpath(3) == ds.findUpath(7))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }
    return 0;
}