#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& v){
    // *************************************************
    // WRITE YOUR CODE HERE
    int low = 0;
    int high = n+1;
    while (low <= high) {
        int mid = (low + high)/2;
        if (mid >= v[mid]){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout<<low<<endl;
    // *************************************************
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s; // Read number of sub-test-cases within an input file
    while(s > 0)
    {
        s--;
        // *************************************************
        // WRITE YOUR CODE HERE TO READ THE INPUT FOR EACH SUB-TEST-CASE
        vector<int> v;
        int n;
        cin>>n;
        for(int i=0;i<=n;i++){
            int in;
            cin>>in;
            v.push_back(in);
        }
        solve(n,v);
        // *************************************************
    }
    return 0;
}
