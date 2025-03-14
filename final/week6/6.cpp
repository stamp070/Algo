#include <bits/stdc++.h>
using namespace std;
int Count = 0;
// ทำdydamicไงวะ????
int walk(int n, int m, int sum)
{
    if (sum > n)
        return 0;

    if (sum == n)
    {
        Count += 1;
        return 1;
    }
    for (int i = 1; i <= m; i++)
    {
        sum += i;
        // cout << "i:" << i << " sum:" << sum << endl;
        walk(n, m, sum);
        sum -= i;
        // cout << "sum after:" << sum << endl;
    }
    return sum;
}
vector<int> memo(10000, 0);
vector<int> memo2(10000, -1);
// btm-up
int walkdydamic(int n, int m)
{
    memo[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i - j < 0)
                continue;
            memo[i] += memo[i - j];
        }
    }
    return memo[n];
}
// top-down
int walktopdown(int n, int m)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (memo2[n] != -1)
    {
        return memo2[n];
    }

    int step = 0;
    for (int i = 1; i <= m; i++)
    {

        step += walktopdown(n - i, m);
    }
    memo2[n] = step;
    return memo2[n];
}
int main()
{
    int n, m;
    cin >> n >> m;
    walk(n, m, 0);
    cout << Count << endl;
    cout << walkdydamic(n, m) << endl;
    cout << walktopdown(n, m);
    return 0;
}
