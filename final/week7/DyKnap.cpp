#include <bits/stdc++.h>
using namespace std;
int dyknap(vector<pair<int, int>> bag, vector<vector<int>> table, int n, int k)
{
    for (int i = 0; i <= k; i++)
    {

        table[0][i] = 0;
        if (i >= bag[1].second)
            table[1][i] = bag[1].first;
    }
    for (int i = 0; i <= n; i++)
    {
        table[i][0] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            table[i][j] = table[i - 1][j];
            if (j - bag[i].second >= 0)
            {
                table[i][j] = max(table[i - 1][j], table[i - 1][j - bag[i].second] + bag[i].first);
                // cout << "table (" << i << "," << j << "): " << table[i][j] << endl;
            }
        }
    }
    return table[n][k];
}
int topdown(vector<pair<int, int>> bag, vector<vector<int>> table, int n, int k)
{
    if (k < 0)
        return -10000;
    if (n == 0 || k == 0)
        return 0;
    if (n == 1 && k >= bag[1].second)
        return bag[1].first;

    if (table[n][k] != -1)
        return table[n][k];
    table[n][k] = max(topdown(bag, table, n - 1, k), topdown(bag, table, n - 1, k - bag[n].second) + bag[n].first);
    // cout << "table (" << n << "," << k << "): " << table[n][k] << endl;

    return table[n][k];
}
int main()
{
    int n, max_w;
    cin >> n >> max_w;
    //         val, weight
    vector<pair<int, int>> bag(n + 1);
    vector<vector<int>> table(n + 1, vector<int>(max_w + 1));
    vector<vector<int>> table2(n + 1, vector<int>(max_w + 1, -1));
    for (int i = 1; i <= n; i++)
        cin >> bag[i].first;
    for (int i = 1; i <= n; i++)
        cin >> bag[i].second;

    cout << dyknap(bag, table, n, max_w) << endl;
    cout << "------------------------" << endl;
    cout << topdown(bag, table2, n, max_w);
    return 0;
}
/*
4 8
1 2 5 6
2 3 4 5

4 7
1 4 5 7
1 3 4 5

7 15
3 4 5 25 20 12 11
2 3 4 15 10 8 7
*/
