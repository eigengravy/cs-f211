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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0 ; i<n ; i++){
            cin>>a[i];
        }
        vector<int> ans = solve(a,k);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
