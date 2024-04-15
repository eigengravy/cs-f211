#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> &edges, int steps, vector<int> &vis, vector<int> &pathVis, vector<int> &dist)
{
    vis[node] = 1;
    pathVis[node] = 1;
    dist[node] = steps;
    if (edges[node] != -1)
    {
        if (!vis[edges[node]])
        {
            return dfs(edges[node], edges, steps + 1, vis, pathVis, dist);
        }
        else if (pathVis[edges[node]])
        {
            return steps - dist[edges[node]] + 1;
        }
    }
    pathVis[node] = 0;
    return -1;
}
int solve(int n, vector<int> &edges)
{
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    vector<int> dist(n, 0);
    int maxLength = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            maxLength = max(maxLength, dfs(i, edges, 1, vis, pathVis, dist));
        }
    }
    return maxLength;
}
