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
    unordered_map<int, int> freq;
    for (int num : a)
    {
        freq[num]++;
    }

    int max_count = 0;
    int most_frequent = a[0];
    for (auto &pair : freq)
    {
        if (pair.second > max_count)
        {
            max_count = pair.second;
            most_frequent = pair.first;
        }
    }

    return to_string(most_frequent);
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
