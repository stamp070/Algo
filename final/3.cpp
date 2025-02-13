#include <iostream>
#include <algorithm>
using namespace std;

void permute(int X[], int k, int st, int depth, int n, int &count)
{
    if (depth == k)
    {
        for (int i = 0; i < k; i++)
        {
            cout << X[i];
            if (i < k - 1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
        count++;
        return;
    }

    for (int i = st; i <= n; i++)
    {
        X[depth] = i;
        permute(X, k, i + 1, depth + 1, n, count);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int X[k];
    int count = 0;

    permute(X, k, 1, 0, n, count);

    cout << count << endl;

    return 0;
}
