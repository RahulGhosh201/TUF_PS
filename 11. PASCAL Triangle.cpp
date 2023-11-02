// either we will be asked to print the total triangle upto n rows or we will be told to return the element present in a specific row and column also you can be asked to print the nth row

#include <bits/stdc++.h>
using namespace std;

// things to observe in a pascal triangle,
// all the first and last element of any rows is 1
// the no of elements present in a row is the number of that row

// also if you are asked to return the element of rth row and cth column then the answer is (r-1)c(c-1)
// complexity: o(n) and o(1)
// int fact(int n)
// {
//     if (n == 0)
//         return 1;
//     int res = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         res = res * i;
//         return res;
//     }
// }

// int ncr(int n, int r)
// {
//     return fact(n) / (fact(r) * fact(n - r));
// }

vector<vector<int>> generate(int n)
{
    vector<vector<int>> r(n); // n number of rows
    for (int i = 0; i < n; i++)
    {
        // as we know for each row no of column would be equal to the no of rows
        r[i].resize(i + 1);
        // as we have seen that in the pascal triangle all the first and last element of each row is 1. So we are initializing it
        r[i][0] = r[i][i] = 1;

        // now we are traversing from the first column to the second last column
        for (int j = 1; j < i; j++)
        {
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j]; // j-1 columnth value + j columnth value of previous row
        }
        return r;
    }
}

int main()
{
    int n = 5;

    vector<vector<int>> ans = generate(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

// if you want to print the nth row than just  print from (r-1) c 0 to (r-1)c(r-1)
// complexity: o(n) and o(n)

// to print the triangle complexity: o(n^2) and o(n^2)
