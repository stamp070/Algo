#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Union(int a[], int b[], int n)
{
    int Max = max(*max_element(a, a + n), *max_element(b, b + n));
    vector<int> Union(Max + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (Union[a[i]] == 0)
        {
            cout << a[i] << " ";
            Union[a[i]]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (Union[b[i]] == 0)
        {
            cout << b[i] << " ";
            Union[b[i]]++;
        }
    }
    cout << endl;
}
void intersection(int a[], int b[], int n)
{
    int Max = max(*max_element(a, a + n), *max_element(b, b + n));
    vector<int> Intersect(Max + 1, 0);
    for (int i = 0; i < n; i++)
    {
        Intersect[b[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (Intersect[a[i]] > 0)
        {
            cout << a[i] << " ";
            Intersect[a[i]] = 0;
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    intersection(a, b, n);
    Union(a, b, n);

    return 0;
}
