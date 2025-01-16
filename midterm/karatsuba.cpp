#include <bits/stdc++.h>
using namespace std;
long long power(long long base, int exp)
{
    long long result = 1;
    while (exp--)
    {
        result *= base;
    }
    return result;
}
int karatsuba(int a, int b)
{
    // เหลือเลขตัวเดียว
    if (a < 10 || b < 10)
        return a * b;
    // แปลงเป็น string หาความยาวอันไหนสูงสุด
    int n = max(to_string(a).length(), to_string(b).length());
    int n2 = n / 2;
    /*
    x = 1234 / 100 = 12 (ส่วนสูงของ a)
    y = 1234 % 100 = 34 (ส่วนต่ำของ a)
    z = 5678 / 100 = 56 (ส่วนสูงของ b)
    w = 5678 % 100 = 78 (ส่วนต่ำของ b)
    */
    // เอาเลขฝั่งซ้าย
    long long a1 = a / power(10, n2);
    // เอาเลขฝั้งขวา
    long long a2 = a % power(10, n2);
    // เอาเลขฝั่งซ้าย
    long long b1 = b / power(10, n2);
    // เอาเลขฝั้งขวา
    long long b2 = b % power(10, n2);
    long long A = karatsuba(a1, b1);
    long long B = karatsuba(a2, b2);
    long long C = karatsuba(a1 + a2, b1 + b2);
    cout << "A = " << A << " B = " << B << " C = " << C << endl;

    return A * power(10, 2 * n2) + (C - A - B) * power(10, n2) + B;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << karatsuba(a, b) << endl;
    return 0;
}