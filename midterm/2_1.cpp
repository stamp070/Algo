#include <iostream>
#include <algorithm>
using namespace std;
int interpolationsearch(int arry[], int value, int low, int high)
{
    int mid;
    if (low <= high && value <= arry[high] && value >= arry[low])
    {
        mid = low + ((double)(high - low) / (arry[high] - arry[low])) * (value - arry[low]);
        cout << mid << " ";
        if (arry[mid] == value)
        {
            return mid;
        }
        if (arry[mid] < value)
        {
            return interpolationsearch(arry, value, mid + 1, high);
        }
        if (arry[mid] > value)
        {
            return interpolationsearch(arry, value, low, mid - 1);
        }
    }
    return -1;
}
int main()
{
    int n, find;
    cin >> n >> find;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    interpolationsearch(A, find, 0, n - 1);
}