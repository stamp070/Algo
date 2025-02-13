#include <iostream>
#include <algorithm>
using namespace std;
int book[3] = {0};
int checkcost(int a[], int x[], int n, int cost)
{
    int sum = 0;
    int idx = 0, count = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += x[i] * a[i - 1];
        if (x[i] == 1)
        {
            count++;
        }
    }
    if (sum < cost && count == 3)
    {

        for (int i = 1; i <= n; i++)
        {
            if (x[i] == 1)
                book[idx++] = a[i - 1];
        }
    }
}
int subset1(int a[], int x[], int l, int r, int cost)
{
    if (l == r)
    {
        checkcost(a, x, r, cost);
    }
    else
    {
        x[l + 1] = 1;
        subset1(a, x, l + 1, r, cost);
        x[l + 1] = 0;
        subset1(a, x, l + 1, r, cost);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], x[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    subset1(a, x, 0, n, m);
    sort(book, book + 3);
    for (int i = 0; i < 3; i++)
        cout << book[i] << endl;
    return 0;
}
