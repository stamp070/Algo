#include <bits/stdc++.h>
using namespace std;
int accessV(vector<vector<int>> g, vector<int> s, int n)
{
    vector<vector<int>> count(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i])
        {
            if (i != j) // กันวนตัวเอง
            {
                count[j].push_back(i);
            }
        }
    }
    for (auto i : s)
    {
        if (!count[i].empty())
        {
            for (auto j : count[i])
            {
                cout << j << " ";
            }
        }
        else
        {
            cout << 0 << " ";
        }

        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n * 2);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        while (true)
        {
            int b;
            cin >> b;
            if (b == 0)
                break;
            g[a].push_back(b);
        }
    }
    int k;
    cin >> k;
    vector<int> s(k);
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
    }
    accessV(g, s, n);
    return 0;
}