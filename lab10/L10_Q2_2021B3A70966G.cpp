#include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

long long solve(int n, vector<vector<int>> &edges)
{

    vector<vector<pair<int, int>>> adj_from_src(n+1);
    vector<vector<pair<int, int>>> adj_from_dst(n+1);

    for (int i = 0; i < edges.size(); i++)
    {
        auto it = edges[i];
        int u = it[0];
        int v = it[1];
        int w = it[2];

        adj_from_src[u].push_back({v, w});
        adj_from_dst[v].push_back({u, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    vector<long long> cost_from_src(n + 1, LONG_LONG_MAX);
    pq.push({0, 1});
    cost_from_src[1] = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        for (auto it : adj_from_src[top.second])
        {
            int v = it.first;
            int w = it.second;
            if (cost_from_src[v] > top.first + w)
            {
                cost_from_src[v] = top.first + w;
                pq.push({top.first + w, v});
            }
        }
    }

    vector<long long> cost_from_dst(n + 1, LONG_LONG_MAX);
    pq.push({0, n});
    cost_from_dst[n] = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        for (auto it : adj_from_dst[top.second])
        {
            int v = it.first;
            long long w = it.second;
            if (cost_from_dst[v] > top.first + w)
            {
                cost_from_dst[v] = top.first + w;
                pq.push({top.first + w, v});
            }
        }
    }

    long long min_cost = LONG_LONG_MAX;
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        long long w = it[2];

        min_cost = min(cost_from_src[u] + w / 2 + cost_from_dst[v], min_cost);
    }

    return min_cost;
}
