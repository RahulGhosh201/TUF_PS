// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

#include <bits/stdc++.h>
using namespace std;

// brute force approach is to run a loop from 1 to n and ans=ans*x and if n<0 then add another step i.e. ans=1/ans
// n and 1
// double soln(int x, int n)
// {
//     double ans = 1;
//     for (int i = 0; i < n; i++)
//     {
//         ans = ans * x;
//     }
//     return ans;
// }

// optimized approach logn
double soln(double x, double n)
{
    double ans = 1;
    long nn = n;
    while (nn > 0)
    {
        if (nn % 2 == 1)
        {
            ans = ans * x;
            nn -= 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    return ans;
}

int main()
{
    double x = 2, n = -2, ans = 0;
    if (n >= 0)
    {
        ans = soln(x, n);
    }
    else
    {
        ans = soln(x, (n * (-1)));
        ans = 1 / ans;
    }

    cout << "Ans: " << ans << endl;
}