#include <bits/stdc++.h>
using namespace std;
double bfs(vector<vector<int>> g, vector<int> visited, int src)
{
    vector<int> dist(g.size(), 500);
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int node : g[temp])
        {
            if (!visited[node])
            {
                visited[node] = 1;
                dist[node] = dist[temp] + 1;
                q.push(node);
            }
        }
    }
    double mean = 0;
    for (int i = 1; i < g.size(); i++)
    {
        mean += dist[i];
        cout << dist[i] << " ";
    }
    cout << endl;
    mean = mean / (g.size() - 1);

    return mean; // เรา initial size + 1
}
int bestnode(vector<vector<int>> g)
{
    vector<int> visited(g.size(), 0);
    double time = 0, best_time = 10000, best_node;
    for (int i = 1; i < g.size(); i++)
    {
        cout << "i: " << i << endl;
        fill(visited.begin(), visited.end(), 0);
        time = bfs(g, visited, i);
        cout << "mean-time: " << time << endl;

        if (time < best_time)
        {
            best_time = time;
            best_node = i;
        }
    }
    cout << best_node;
}
int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> g(v + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bestnode(g);
    return 0;
}