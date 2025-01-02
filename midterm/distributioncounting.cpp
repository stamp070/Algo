#include <iostream>
#include <algorithm>
using namespace std;
int *distributioncounting(int a[], int n)
{
    int l, u;
    l = *min_element(a, a + n);
    u = *max_element(a, a + n);
    int range = u - l + 1;
    int freq[range];
    int *ans = new int[n];
    for (int i = 0; i < range; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        freq[a[i] - l]++;
    }
    for (int i = 1; i < range; i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ans[freq[a[i] - l] - 1] = a[i];
        freq[a[i] - 1]--;
    }

    return ans;
}
int main()
{
    int arr[] = {16, 25, 2, 54, 36, 9, 12, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *ans = distributioncounting(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}