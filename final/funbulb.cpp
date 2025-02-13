#include <iostream>
using namespace std;
int ex = 0, count = 0;
int something(int x[], int n, int k)
{
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
            c++;
    }
    if (c == k)
    {
        int check = 1;
        for (int i = 1; i <= n; i++)
        {
            if (x[i + 1] == 1 && x[i] == 1)
                check = 0;
        }
        if (check)
            count++;
    }
}
void subset1(int x[], int l, int r, int k)
{
    // check
    int c = 0;
    for (int i = 1; i <= r; i++)
    {
        if (x[i] == 1)
            c++;
    }
    if (c > k)
    {
        return;
    }

    // base
    if (l == r)
    {
        something(x, r, k);
    }
    else
    {
        ex++;
        x[l + 1] = 1;
        subset1(x, l + 1, r, k);
        x[l + 1] = 0;
        subset1(x, l + 1, r, k);
    }
}
int main()
{
    int n, h;
    cin >> n >> h;
    int x[n + 1] = {0};

    subset1(x, 0, n, h);
    cout << "recur: " << ex << " count: " << count;
    return 0;
}
