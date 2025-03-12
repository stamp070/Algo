#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 2, vector<char>(m + 2)); // + 1 เพื่อให้ access ได้เลย + อีก 1 เพื่อเป็นตัวเช็คว่าเกิน array

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    int x, y;
    cin >> x >> y;

    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int count = 0;
    char paint = g[x][y]; // L or W
    cout << "paint: " << paint << endl;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        // check boundaries
        if (top.first > n || top.first < 1 || top.second > m || top.second < 1)
            continue;

        cout << "first: " << top.first << " second: " << top.second << endl;
        count++;

        if (!visited[top.first + 1][top.second] && g[top.first + 1][top.second] == paint) // right
        {
            q.push({top.first + 1, top.second});
            visited[top.first + 1][top.second] = true;
        }

        if (!visited[top.first][top.second + 1] && g[top.first][top.second + 1] == paint) // down
        {
            q.push({top.first, top.second + 1});
            visited[top.first][top.second + 1] = true;
        }
        if (!visited[top.first][top.second - 1] && g[top.first][top.second - 1] == paint) // top
        {
            q.push({top.first, top.second - 1});
            visited[top.first][top.second - 1] = true;
        }
        if (!visited[top.first - 1][top.second] && g[top.first - 1][top.second] == paint) // left
        {
            q.push({top.first - 1, top.second});
            visited[top.first - 1][top.second] = true;
        }
    }
    cout << count;
    return 0;
}