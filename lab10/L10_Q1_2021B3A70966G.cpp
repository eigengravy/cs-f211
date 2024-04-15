#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &points)
{

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<int> visited(points.size(), 0);

    pq.push({0, 0});
    int cost = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        if (visited[top.second])
            continue;

        visited[top.second] = 1;
        cost += top.first;

        for (int i = 0; i < points.size(); i++)
        {
            vector<int> src = points[top.second];
            vector<int> dst = points[i];
            long long dist = abs(src[0] - dst[0]) + abs(src[1] - dst[1]);

            if (top.second != i)
            {
                pq.push({dist, i});
            }
        }
    }

    return cost;
}
