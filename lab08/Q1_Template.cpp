#include <bits/stdc++.h>
#include "__STUDENTPROGRAM__"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        int m;
        cin >> n >> m;
        vector< vector<char> > matrix(n,vector<char>(m));
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                cin >> matrix[i][j];
            }
        }
        int ans = solve(matrix);
        cout << ans <<endl;
    }

}
