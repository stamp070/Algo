#include <bits/stdc++.h>
using namespace std;
int floyd(vector<vector<int>> &g, int n)
{
    for (int i = 0; i <= n; i++)
    {
        g[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << k << " " << i << " " << j << endl;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    // incase: src/dest node ไม่เกิน n
    vector<vector<int>> g(v + 1, vector<int>(v + 1, 50000));
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        g[s][d] = w;
    }
    floyd(g, v);
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/* a = 1, b = 2, c = 3, d = 4
4 6
1 2 9
2 3 1
3 1 4
1 4 1
4 2 2
4 3 10


*/
