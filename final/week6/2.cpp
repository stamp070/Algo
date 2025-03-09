#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo(100, vector<int>(100, -1));
int C(int n, int k)
{
    // base case
    if (n == 0 || k == 0)
        return 1;
    if (n == k)
        return 1;

    if (memo[n][k] != -1)
        return memo[n][k];
    memo[n][k] = C(n - 1, k - 1) + C(n - 1, k);
    return memo[n][k];
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << C(n, k);
    return 0;
}