#include <bits/stdc++.h>
using namespace std;

// Function to check sum of digit using recursion
int sumofdigits(int n)
{
    if (n == 0)
    return 0;
    return (n % 10 + sumofdigits(n / 10));
}

int main()
{
    unsigned int n;
    cin >> n;
    cout << sumofdigits(n) << endl;
    return 0;
}