#include <bits/stdc++.h>
using namespace std;
int detectCycle(vector<vector<int>> g, int src, int n)
{
    queue<pair<int, int>> q;
    vector<bool> visited(n, false);

    q.push({src, -1});
    visited[src] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto i : g[node])
        {
            cout << "i = " << i << " parent = " << parent << endl;
            if (!visited[i])
            {
                visited[i] = true;
                q.push({i, node});
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n * 2);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        while (true)
        {
            int b;
            cin >> b;
            if (b == 0)
                break;
            g[a].push_back(b);
        }
    }

    if (detectCycle(g, 4, n))
        cout << 1;
    else
        cout << 0;
    return 0;
}