#include <iostream>
using namespace std;
int min_v = 1000;
int something(int f[], int b[], int x[], int n)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        // สลับกัน + left/right
        if (x[i] == 1)
        {

            sum1 += f[i - 1];
            sum2 += b[i - 1];
        }
        else
        {
            sum1 += b[i - 1];
            sum2 += f[i - 1];
        }
    }
    int val = abs(sum1 - sum2);
    if (val < min_v)
    {
        min_v = val;
    }
}
int subset1(int f[], int b[], int x[], int l, int r)
{
    if (l == r)
    {
        something(f, b, x, r);
    }
    else
    {
        x[l + 1] = 1;
        subset1(f, b, x, l + 1, r);
        x[l + 1] = 0;
        subset1(f, b, x, l + 1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int l[n], r[n], x[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
    }
    subset1(l, r, x, 0, n);
    cout << min_v;
    return 0;
}
