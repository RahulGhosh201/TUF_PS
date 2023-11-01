// Input:
// N = 4
// K = 0
// Output:
// No
// Explanation:
// Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
#include <bits/stdc++.h>
using namespace std;

bool soln(int n, int k)
{
    vector<int> bin;
    while (n > 0)
    {
        bin.push_back(n % 2);
        n = n / 2;
    }

    if (bin[k])
    {
        return true;
    }
    return false;
    // return n>>k&1;
}

int main()
{
    int n = 4, k = 2;
    bool ans = soln(n, k);
    if (ans == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}