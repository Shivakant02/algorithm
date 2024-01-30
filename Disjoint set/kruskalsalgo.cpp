#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);

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
};
class Graph
{
    vector<vector<int>> edges;
    int V;

public:
    Graph(int v)
    {
        this->V;
    }
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, u, v});
    }
    void kruskals_mst()
    {
        sort(edges.begin(), edges.end());
        DisjointSet s(V);
        int minCost = 0;
        cout << "Following are the edges in the constructed MST" << endl;
        cout << "edge 1\t edge 2\t weight" << endl;
        for (auto it : edges)
        {
            int w = it[0];
            int u = it[1];
            int v = it[2];
            if (s.findUpath(u) != s.findUpath(v))
            {
                s.unionByRank(u, v);
                minCost += w;
                cout << u << "\t " << v << "\t " << w << endl;
            }
        }
        cout << "The minimum cost is :" << minCost;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    g.kruskals_mst();
    return 0;
}