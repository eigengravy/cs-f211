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
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            points.push_back({a, b});
        }

        cout << solve(points) << endl;
    }
}
