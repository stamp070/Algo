#include <bits/stdc++.h>
using namespace std;
int prim(vector<pair<int, int>> g[], int src, int n)
{
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 10000);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //    weight,src
    pq.push({0, src});
    visited[src] = true;
    dist[src] = 0;

    int sum = 0;
    while (!pq.empty())
    {
        int temp = pq.top().second;
        visited[temp] = true;

        pq.pop();
        for (auto i : g[temp])
        {
            int v = i.first;
            int weight = i.second;
            if (!visited[v] && weight < dist[v])
            {
                // cout << "node: " << v << " weight: " << weight << endl;
                dist[v] = weight;
                pq.push({dist[v], v});
                sum += dist[v];
            }
        }
    }

    return sum;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> g[v + 1];

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        // g[b].push_back({a, c});
    }
    int dest;
    cin >> dest;
    cout << prim(g, dest, v);
    return 0;
}
