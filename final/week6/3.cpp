#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo(100, vector<int>(100, -1));
int ant(int n, int m, int x, int y, vector<vector<int>> ar)
{
    if (x > n || y > m)
        return 0;
    if (x == n && y == m)
        return ar[x][y];

    if (memo[x][y] != -1)
        return memo[x][y];

    int left = ant(n, m, x + 1, y, ar);
    int right = ant(n, m, x, y + 1, ar);
    memo[x][y] = max(left, right) + ar[x][y];

    return memo[x][y];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ar(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        {
            for (int j = 1; j <= m; j++)
                cin >> ar[i][j];
        }
    }

    cout << ant(n, m, 1, 1, ar);
    return 0;
}