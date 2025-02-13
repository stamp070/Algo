#include <iostream>
using namespace std;
int max_v = -100;
int ans;
int cal(int a[], int x[], int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] != x[i + 1])
        {
            sum += x[i] * a[i - 1];
        }
    }
    if (sum > max_v)
    {
        max_v = sum;
    }
    return max_v;
}
int subset1(int a[], int x[], int l, int r)
{
    if (l == r)
    {
        ans = cal(a, x, r);
    }
    else
    {
        x[l + 1] = 1;
        subset1(a, x, l + 1, r);
        x[l + 1] = 0;
        subset1(a, x, l + 1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n], x[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    subset1(a, x, 0, n);
    cout << ans << endl;
    return 0;
}
