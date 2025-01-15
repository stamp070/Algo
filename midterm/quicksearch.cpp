#include <iostream>
#include <algorithm>
using namespace std;
void printing(int arr[], int l, int h)
{
    for (int i = l; i <= h; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int medianOfThree(int arr[], int low, int high)
{
    int mid = (high + low) / 2;
    if (arr[low] > arr[mid])
    {
        swap(arr[low], arr[mid]);
    }
    if (arr[low] > arr[high])
    {
        swap(arr[low], arr[high]);
    }
    if (arr[mid] > arr[high])
    {
        swap(arr[mid], arr[high]);
    }
    swap(arr[mid], arr[high - 1]);
    return high - 1;
}
int partition(int arr[], int low, int high)
{
    printing(arr, low, high);
    int pivot = medianOfThree(arr, low, high);
    cout << "---------------------" << endl;
    printing(arr, 0, 8);
    cout << "pivot = " << arr[pivot] << " index = " << pivot << endl;
    cout << "---------------------" << endl;

    int i = low;
    int j = pivot;
    while (1)
    {
        do
        {
            i++;
        } while (arr[i] <= arr[pivot]);
        do
        {
            j--;
        } while (arr[j] > arr[pivot]);
        printing(arr, low, high);

        cout << "i = " << i << " j = " << j << endl;
        if (i >= j)
        {
            break;
        }

        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[pivot]);
    printing(arr, low, high);

    cout << "end" << endl;
    return i;
}
int quickSelect(int arr[], int low, int high, int k)
{
    if (low == high)
        return arr[low];
    int p = partition(arr, low, high);
    cout << "p = " << p << endl;
    if (k == p) // case k = Pivot position
        return arr[k];
    else if (k < p) // case k  L
        return quickSelect(arr, low, p - 1, k);
    else
    { // case k  R
        k = k - low;
        return quickSelect(arr, p + 1, high, k);
    }
}
int main()
{
    int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", quickSelect(arr, 0, n - 1, k));
    return 0;
}