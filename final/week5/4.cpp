#include <bits/stdc++.h>
using namespace std;
int find(vector<int> parent, int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
void Union(vector<int> parent, int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    parent[xroot] = yroot;
}
int is_cycle(vector<int> parent, int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    return x == y ? 1 : 0;
}
int kruscal(vector<pair<int, int>> g[], int n)
{
    vector<int> parent(n + 1, -1);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 1; i < n; i++)
    {
        for (auto j : g[i])
        {
            pq.push({j.second, {i, j.first}});
        }
    }

    int loop = 0, flag = 0, edges = 0;
    while (loop < n - 1)
    {
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        int weight = pq.top().first;

        pq.pop();

        if (!is_cycle(parent, u, v))
        {
            loop++;
            Union(parent, u, v);
            cout << "(" << u << ", " << v << "), " << weight << endl;
            flag += weight; // sum flag
            edges++;
        }
    }
    cout << "edges: " << edges << endl;
    return flag - edges;
}
int prim(vector<pair<int, int>> g[], int src, int n)
{
    vector<int> dist(n + 1, 50000);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int temp = pq.top().second;
        cout << temp << " ";
        pq.pop();
        for (auto i : g[temp])
        {
            int v = i.first;
            int weight = i.second;

            if (!visited[v] && weight < dist[v])
            {
                visited[v] = true;
                dist[v] = weight;
                parent[v] = temp;
                pq.push({dist[v], v});
            }
        }
    }
    // int sum = 0;
    // for (auto i : dist)
    // {
    //     if (i != 50000)
    //     {

    //         cout << i << " ";
    //     }
    // }
    cout << endl;
    // return sum;
}
int checknode(vector<pair<int, int>> g[], int n)
{
    int flag = 0, min_flag = 1000;
    for (int i = 1; i <= n; i++)
    {
        flag = prim(g, i, n);
        if (flag < min_flag)
            min_flag = flag;
    }
    // cout << min_flag << endl;
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
        g[b].push_back({a, c});
    }

    // cout << kruscal(g, v);
    checknode(g, v);
    return 0;
}
