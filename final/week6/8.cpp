#include <bits/stdc++.h>
using namespace std;
vector<double> memo(1000005, 0);
// normal
double findMean(vector<int> ar, int n)
{
    if (n == 1)
    {
        return ar[1];
    }

    memo[n] = (findMean(ar, n - 1) * (n - 1) + ar[n]) / n;
    return memo[n];
}

double findMean2(vector<int> ar, int n, int sum, int index)
{
    if (index == n + 1)
    {
        return (double)sum / n;
    }

    return findMean2(ar, n, sum + ar[index], index + 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    cout << findMean(ar, n) << endl;
    cout << findMean2(ar, n, 0, 1);
    return 0;
}