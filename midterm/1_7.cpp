#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n, find;
    cin >> n >> find;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> ans;
    int a, b;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == find)
            {
                a = arr[i];
                b = arr[j];
                if (ans.find(a) == ans.end())
                {
                    ans[a] = b;
                    cout << a << " " << b << endl;
                }
            }
        }
    }
    if (ans.empty())
    {
        cout << -1;
    }
    return 0;
}
// 1 9 9 1 9 6 4 4 6
