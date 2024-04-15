#include <bits/stdc++.h>
#include "__STUDENTPROGRAM__"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        t--;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> meetings(m);
        for (int i = 0; i < m; i++)
        {
            int start, end;
            cin >> start >> end;
            meetings[i] = {start, end};
        }

        vector<int> cnt = solve(n, m, meetings);
        for (int &x : cnt)
        {
            cout << x << " ";
        }
    }
}
