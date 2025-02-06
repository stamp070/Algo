#include <iostream>
#include <algorithm>
using namespace std;

void permute(string X[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            cout << X[i];
        }
        cout << endl;
    }

    for (int i = start; i <= end; i++)
    {

        swap(X[start], X[i]);
        sort(X + start + 1, X + end + 1);
        permute(X, start + 1, end);
        swap(X[start], X[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    string s[n];

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    permute(s, 0, n - 1);

    return 0;
}
