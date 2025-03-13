#include <bits/stdc++.h>
using namespace std;
#define Range 500000
int CalPath(int max_p, int w)
{
    int count = 0;
    while (max_p >= 0)
    {
        max_p -= w;
        max_p++;
        count++;
    }
    return count;
}
int Prim(vector<pair<int, int>> g[], int src, int dest, int max_p)
{
    vector<bool> visited(Range, false);
    vector<int> dist(Range, 50000);
    vector<int> parent(Range, -2);

    queue<int> pq;

    pq.push(src);
    dist[src] = 0;
    while (!pq.empty())
    {
        int cur = pq.front();
        pq.pop();
        visited[cur] = true;
        for (pair<int, int> i : g[cur])
        {

            int v = i.first;
            int w = i.second;
            int p = CalPath(max_p, w);
            if (v == dest)
            {
                dist[v] = min(dist[v], max(dist[cur], p));
            }
            else if (!visited[v])
            {
                pq.push(v);
                if (dist[v] == 50000)
                {
                    dist[v] = max(p, dist[cur]);
                }
                else
                    dist[v] = min(dist[v], max(dist[cur], p));
            }
        }
    }
    cout << dist[dest] << endl;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> g[e + 1];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        g[s].push_back({d, w});
        g[d].push_back({s, w});
    }
    int src, dest, num;
    cin >> src >> dest >> num;
    Prim(g, src, dest, num);
    return 0;
}
