#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo1(10000, vector<int>(10000, -1));
vector<int> memo2(10000, -1);
int F(int n, int k)
{
    for (int i = 0; i <= n; i++)
    {
        memo1[i][0] = 1;
        memo1[i][1] = 1;
        memo1[i][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            if (i > j)
            {
                memo1[i][j] = memo1[i - 1][j] + memo1[i - 1][j - 2];
            }
        }
    }
    return memo1[n][k];
}
int G(int a)
{
    memo2[0] = 0;
    memo2[1] = 1;
    memo2[2] = 1;

    for (int i = 3; i <= a; i++)
    {
        memo2[i] = memo2[i - 1] + memo2[i - 2] - memo2[i - 3];
    }
    return memo2[a];
}
int main()
{
    cout << F(6, 4) << endl;
    cout << G(7) << endl;
    return 0;
}