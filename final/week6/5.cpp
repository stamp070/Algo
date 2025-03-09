#include <bits/stdc++.h>
using namespace std;
vector<int> memo(10000, -1);
int dydamic(int a)
{
    if (a == 0 || a == 1)
        return 1;
    if (memo[a] != -1)
        return memo[a];
    memo[a] = dydamic(a - 1) * 3 + dydamic(a - 2) * 2;
    return memo[a];
}
int main()
{
    int n;
    cin >> n;
    cout << dydamic(n);
    return 0;
}