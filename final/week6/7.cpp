#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo(10000, vector<int>(10000, -1));
int tiger(int m, int n)
{
    if (m < 1 || n < 1)
        return 0;
    if (m == 1 && n == 1)
        return 1;
    if (memo[m][n] != -1)
        return memo[m][n];
    memo[m][n] = tiger(m - 1, n) + tiger(m, n - 1);
    return memo[m][n];
}
int main()
{
    int m, n;
    cin >> m >> n;
    cout << tiger(m, n);
    return 0;
}