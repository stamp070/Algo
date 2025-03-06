#include <bits/stdc++.h>
using namespace std;
int notreach(vector<vector<int>> g, int src, int distance)
{
    vector<int> dist(g.size(), -1);
    vector<bool> visited(g.size(), false);

    dist[src] = 0;
    visited[src] = true;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int node : g[temp])
        {
            if (!visited[node])
            {

                dist[node] = dist[temp] + 1;
                q.push(node);
                visited[node] = true;
            }
        }
    }
    int count = 0;
    for (auto i : dist)
    {
        if (i > distance)
            count++;
        // cout << i << " ";
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1); // n ตัวเริ่มที่ 1 จบ n เลย + 1
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        g[a].push_back(b);
    }
    int k, m;
    cin >> k >> m;

    cout << notreach(g, k, m);
    return 0;
}

/*
7
1 2
1 4
1 5
2 3
2 5
3 1
3 6
3 7
4 5
5 4
6 5
6 7
0 0
1 2
*/