#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, find;
    cin >> n >> find;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int min = 1000, temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == find)
            {
                temp = abs(A[i] - A[j]);
            }
            if (temp < min)
            {
                min = temp;
            }
        }
    }
    cout << min << endl;
}