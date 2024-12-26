#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int start, end;
    int max = 0;
    int sum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += A[k];
            }
            if (sum > max)
            {
                max = sum;
                start = i;
                end = j;
            }
        }
    }
    cout << max << endl;
    return 0;
}