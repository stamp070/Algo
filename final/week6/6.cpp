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
        cout << "i:" << i << " sum:" << sum << endl;
        walk(n, m, sum);
        sum -= i;
        // cout << "sum after:" << sum << endl;
    }
    return sum;
}
int main()
{
    int n, m;
    cin >> n >> m;
    walk(n, m, 0);
    cout << Count;
    return 0;
}