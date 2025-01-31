#include <bits/stdc++.h>
using namespace std;
int maxsub(int a[], int n)
{
    int maxsub = a[0];
    int cursum = 0;

    for (int i = 1; i < n; i++)
    {
        if (cursum < 0)
            cursum = 0;
        cursum += a[i];
        maxsub = max(maxsub, cursum);
    }
    return maxsub;
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << maxsub(ar, n);
    return 0;
}
