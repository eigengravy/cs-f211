#include <bits/stdc++.h>
#include "DSA_Vector.cpp"
#include "__STUDENTPROGRAM__" //Don't modify this line. Don't modify this program

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t > 0)
    {
        t--;
        DSA_Vector v;

        cout<<solve(v); //Find the index of the largest and the smallest element
    }
    return 0;
}
