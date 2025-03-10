#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo1(10000, vector<int>(10000, -1));
vector<int> memo2(10000, -1);
int F(int n, int k)
{
        if (k == 0 || k == 1 || n == k)
                return 1;
        // if (k < 1)
        //         return 0;
        if (memo1[n][k] != -1)
                return memo1[n][k];
        memo1[n][k] = F(n - 1, k) + F(n - 1, k - 2);
        return memo1[n][k];
}
int G(int a)
{
        if (a == 0)
                return 0;
        if (a == 1 || a == 2)
                return 1;
        if (memo2[a] != -1)
                return memo2[a];
        memo2[a] = G(a - 1) + G(a - 2) - G(a - 3);
        return memo2[a];
}
int main()
{
        cout << F(6, 4) << endl;
        cout << G(7) << endl;
        return 0;
}