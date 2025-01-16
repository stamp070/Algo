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

long long multiply(long long a, long long b)
{
    if (a < 10 || b < 10)
    {
        return a * b;
    }

    int n = max(to_string(a).length(), to_string(b).length());
    int n2 = n / 2;

    long long a1 = a / power(10, n2);
    long long a2 = a % power(10, n2);
    long long b1 = b / power(10, n2);
    long long b2 = b % power(10, n2);

    long long A = multiply(a1, b1);
    long long B = multiply(a2, b1);
    long long C = multiply(a1, b2);
    long long D = multiply(a2, b2);

    cout << "A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << endl;

    return A * power(10, 2 * n2) + (B + C) * power(10, n2) + D;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << "Result: " << multiply(a, b) << endl;
    return 0;
}
