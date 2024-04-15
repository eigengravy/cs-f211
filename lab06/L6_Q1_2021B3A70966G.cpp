#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int m, vector<vector<int>> &meetings)
{
    vector<int> cnt(n, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int, vector<int>, greater<int>> pqEnd;

    
    for (auto it : meetings)
    {
        pq.push(make_pair(it[0], it[1]));
    }

    int time = pq.top().first;
    int currMeetings = m;
    while(!pq.empty())
    {   
        // std::cout << "time " << time << "pq sizes " << pq.size() << " " << pqEnd.size() << std::endl;

        while(!pqEnd.empty() && pqEnd.top() <= time){
            pqEnd.pop();
        }
        
        if(pq.top().first==time){
            if(pqEnd.size() < n){
                cnt[currMeetings % n]++;
                pqEnd.push(pq.top().second);
                currMeetings--;
            } else {
                pq.push(make_pair(pqEnd.top(),pqEnd.top() + (pq.top().second - pq.top().first)));
            }
            pq.pop();
        }

        time = pq.top().first;
    }

    // sort(cnt.begin(),cnt.end());
    return cnt;
}
