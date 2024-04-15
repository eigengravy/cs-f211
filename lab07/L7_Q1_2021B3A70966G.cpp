#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a, int k)
{

    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<pair<int, int>> pqMax;

    for (int i = 0; i < k; i++)
    {
        pq.push(make_pair(i, a[i]));
        pqMax.push(make_pair(a[i], i));
    }

    ans.push_back(pqMax.top().first);

    for (int i = k; i < a.size(); i++)
    {
        pq.pop();
        pq.push(make_pair(i, a[i]));
        pqMax.push(make_pair(a[i], i));

        while (pqMax.top().second <= i - k)
        {
            pqMax.pop();
        }

        ans.push_back(pqMax.top().first);
    }

    return ans;
}
