#include <bits/stdc++.h>
using namespace std;
int bfs(vector<int> g[], int src)
{
    vector<bool> visited(1000, false);
    vector<int> dist(1000, 10000);

    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i : g[temp])
        {
            if (!visited[i])
            {
                visited[i] = true;
                dist[i] = dist[temp] + 1;
                q.push(i);
            }
        }
    }
    int sum = 0;
    for (int i : dist)
    {
        if (i != 10000)
        {
            sum += i;
        }
    }
    cout << "sum: " << sum << endl;
    return sum;
}
double check(vector<int> g[], vector<int> pages)
{
    int total = 0;
    for (auto i : pages)
    {
        cout << "i: " << i << endl;
        total += bfs(g, i);
    }
    cout << "total: " << total << endl;
    cout << "size: " << pages.size() * (pages.size() - 1) << endl;
    double size = pages.size() * (pages.size() - 1);
    double mean = total / size;
    return mean;
}
int main()
{
    vector<int> g[10000];
    vector<int> pages;
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        g[a].push_back(b);
        if (find(pages.begin(), pages.end(), a) == pages.end())
            pages.push_back(a);
    }

    cout << setprecision(3) << check(g, pages);
    return 0;
}
