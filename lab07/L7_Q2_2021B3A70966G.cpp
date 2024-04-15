#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, long long k)
{

    long long max_len = 0, i = 0, j = 0;

    while (j < a.size())
    {
        k -= a[j];
        if (k == 0)
        {
            max_len = max(max_len, j - i + 1);
        }
        while (k < 0)
        {
            k += a[i];
            i++;
            if (k == 0)
            {
                max_len = max(max_len, j - i + 1);
            }
        }

        j++;
    }

    return max_len;
}
