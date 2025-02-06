#include <iostream>
#include <algorithm>
using namespace std;
int num = 0;
void permute(int X[], int data[], int start, int end, int index, int k)
{

    if (index == k)
    {
        num++;
        for (int i = 0; i < k; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= k - index; i++)
    {
        data[index] = X[i];
        permute(X, data, start + 1, end, index + 1, k);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i = 0; i < n; i++)
    {
        ar[i] = i + 1;
    }
    int data[n];
    permute(ar, data, 0, n - 1, 0, k);
    cout << num;
    return 0;
}
