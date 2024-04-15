#include <bits/stdc++.h>
using namespace std;

// int dfs(int row, int col, int n, int m, vector<string> &grid, vector<vector<bool>> &vis, vector<vector<bool>> &pathVis, int steps)
// {
//     vis[row][col] = true;
//     pathVis[row][col] = true;

//     vector<int> dir = {0, 1, 0, -1, 0};

//     for (int i = 0; i < 4; i++)
//     {
//         int newRow = row + dir[i];
//         int newCol = col + dir[i + 1];

//         if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
//         {
//             if (!vis[newRow][newCol])
//             {
//                 dfs(newRow, newCol, n, m, grid, vis, pathVis, steps + 1);
//             }
//             if (grid[newRow][newCol] == 'A')
//             {
//                 vis[newRow][newCol] = true;
//                 return steps;
//             }
//             else if (grid[newRow][newCol] == '.' && !vis[newRow][newCol])
//             {
//                 vis[newRow][newCol] = true;
//                 return
//             }
//         }
//     }

//     pathVis[row][col] = false;
// }

// int bfs(int n, int m, vector<string> &grid, int x, int y)
// {

//     vector<vector<bool>> vis(n, vector<bool>(m, false));
//     queue<pair<pair<int, int>, int>> q;

//     q.push({{x, y}, 0});

//     while (!q.empty())
//     {
//         auto front = q.front();
//         q.pop();
//         int row = q.front().first.first;
//         int col = q.front().first.second;
//         int steps = q.front().second;

//         vector<int> dir = {0, 1, 0, -1, 0};

//         for (int i = 0; i < 4; i++)
//         {
//             int newRow = row + dir[i];
//             int newCol = col + dir[i + 1];

//             if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
//             {
//                 if (grid[newRow][newCol] == 'A')
//                 {
//                     vis[newRow][newCol] = true;
//                     return steps;
//                 }
//                 else if (grid[newRow][newCol] == '.' && !vis[newRow][newCol])
//                 {
//                     vis[newRow][newCol] = true;
//                     q.push({{newRow, newCol}, steps + 1});
//                 }
//                 // else if (grid[newRow][newCol] == 'M'){
//                 //     return INT_MAX;
//                 // }
//             }
//         }
//     }

//     return INT_MAX;
// }

int solve(int n, int m, vector<string> &grid)
{
    int minSteps = INT_MAX;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<pair<int, int>, int>> q;

    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 'A')
        {
            return 0;
        }
        else if (grid[0][j] == '.' && !vis[0][j])
        {
            vis[0][j] = 1;
            dist[0][j] = 0;
            q.push({{0, j}, 1});
        }
    }

    // bottom edge
    for (int j = 0; j < m; j++)
    {
        if (grid[n - 1][j] == 'A')
        {
            return 0;
        }
        else if (grid[n - 1][j] == '.' && !vis[n - 1][j])
        {
            dist[n - 1][j] = 0;
            vis[n - 1][j] = 1;
            q.push({{n - 1, j}, 1});
        }
    }

    // left edge
    for (int i = 1; i < n - 1; i++)
    {
        if (grid[i][0] == 'A')
        {
            return 0;
        }
        else if (grid[i][0] == '.' && !vis[i][0])
        {
            dist[i][0] = 0;
            vis[i][0] = 1;
            q.push({{i, 0}, 1});
        }
    }

    // right edge
    for (int i = 1; i < n - 1; i++)
    {
        if (grid[i][m - 1] == 'A')
        {
            return 0;
        }
        else if (grid[i][m - 1] == '.' && !vis[i][m - 1])
        {
            vis[i][m - 1] = 1;
            dist[i][m - 1] = 0;
            q.push({{i, m - 1}, 1});
        }
    }

    while (!q.empty())
    {
        int temp = q.size();
        for (int k = 0; k < temp; k++)
        {
            auto front = q.front();
            q.pop();
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            vector<int> dir = {0, 1, 0, -1, 0};

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dir[i];
                int newCol = col + dir[i + 1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && steps < dist[newRow][newCol])
                {
                    dist[newRow][newCol] = steps;
                    if (grid[newRow][newCol] == '.')
                    {
                        q.push({{newRow, newCol}, steps + 1});
                    }
                }
            }
        }
    }

    for (int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='A'){
                return dist[i][j] == INT_MAX ? -1 : dist[i][j];
            }
        }
    }
}
