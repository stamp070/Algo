#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    unordered_set<int> union_temp;
    unordered_set<int> intersect_temp;
    vector<int> union_ans;
    vector<int> intersect_ans;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (union_temp.find(a[i]) == union_temp.end())
        {
            union_temp.insert(a[i]);     // union insert แบบข้างหน้า
            union_ans.push_back(a[i]);   // เลยใช้ vector ที่ insert แบบข้างหลังช่วย
            intersect_temp.insert(a[i]); // เอา a[i] ไปเก็บก่อนแล้วค่อยเช็คว่า
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (union_temp.find(b[i]) == union_temp.end())
        {
            union_temp.insert(b[i]);
            union_ans.push_back(b[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (intersect_temp.find(b[i]) != intersect_temp.end())
        {
            intersect_ans.push_back(b[i]);
        }
    }
    for (auto i : intersect_ans)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : union_ans)
    {
        cout << i << " ";
    }

    return 0;
}