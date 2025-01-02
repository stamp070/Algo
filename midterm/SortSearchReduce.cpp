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
string mostFrequent(vector<int> a)
{
    
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
    string ans = ToString(A);
    cout << ans << endl;
    cout << reduce(ans) << endl;
    cout << mostFrequent(A) << endl;
    return 0;
}
