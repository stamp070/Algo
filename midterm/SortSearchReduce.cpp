#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
string ToString(vector<int> a)
{
    string s = "";
    for (auto i : a)
    {
        s += to_string(i);
    }
    return s;
}
string reduce(string s)
{
    string st;
    st += s[0]; // 121
    for (int i = 1; i < s.size(); i++)
    {
        st += s[i];
        if (s[i] == s[i - 1])
        {
            st.pop_back();
        }
    }
    return st;
}
int findMax(string a)
{
    int Maxnum = 1, num = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[i - 1])
        {
            num++;
        }
        else
        {
            num = 1;
        }
        if (num > Maxnum)
        {
            Maxnum = num;
        }
    }
    return Maxnum;
}
vector<char> mostFrequent(string a)
{
    vector<char> s;
    int Maxnum = 1, num = 1;
    Maxnum = findMax(a);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[i - 1])
        {
            num++;
        }
        else
        {
            num = 1;
        }
        if (num == Maxnum)
        {
            s.push_back(a[i]);
        }
    }
    sort(s.begin(), s.end());

    return s;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    string ans = ToString(A);
    cout << ans << endl;
    vector<char> s = mostFrequent(ans);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << reduce(ans) << endl;

    return 0;
}