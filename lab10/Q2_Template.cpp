#include <bits/stdc++.h>
#include "__STUDENTPROGRAM__"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t > 0)
    {
        t--;
        int n, e;
        cin >> n >> e;
        vector<vector<int>> edges;
        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        cout << solve(n, edges) << endl;
    }
}
