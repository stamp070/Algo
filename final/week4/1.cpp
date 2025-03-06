#include <bits/stdc++.h>
using namespace std;
#define inf 50000
vector<bool> visited(1000, false);

int bfs(vector<vector<int>> g, int st, int en, int n)
{
    queue<int> q;

    vector<int> dist(n + 1, inf);

    dist[st] = 0;
    q.push(st);
    visited[st] = true;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i : g[temp])
        {
            if (!visited[i])
            {
                // cout << i << endl;
                dist[i] = dist[temp] + 1;
                q.push(i);
                visited[i] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    cout << "Ans: " << dist[en];
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(inf);
    for (int i = 0; i < n; i++)
    {
        int A;
        cin >> A;
        while (true)
        {
            int B;
            cin >> B;
            if (B == 0)
                break;
            a[A].push_back(B);
            // cout << "push " << A << " " << B << endl;
        }
    }

    int st, en;
    cin >> st >> en;

    bfs(a, st, en, n);

    return 0;
}