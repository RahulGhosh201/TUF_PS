// Input:
// N = 3
// mat[][] = {{6, 5, 4},
//            {1, 2, 5}
//            {7, 9, 7}}
// Output:
// 29 32
// Explanation:
// The given matrix is
// 6 5 4
// 1 2 5
// 7 9 7
// The elements of upper triangle are
// 6 5 4
//   2 5
//     7
// Sum of these elements is 6+5+4+2+5+7=29.
// The elements of lower triangle are
// 6
// 1 2
// 7 9 7
// Sum of these elements is 6+1+2+7+9+7= 32.

#include <bits/stdc++.h>
using namespace std;

vector<int> soln(vector<vector<int>> mat, int n)
{
    int sum1 = 0, sum2 = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
                sum1 += mat[i][j];
            else if (i > j)
                sum2 = sum2 + mat[i][j];
            else
                sum += mat[i][j];
        }
    }
    return {sum1 + sum, sum2 + sum};
}

int main()
{
    int n = 3;
    vector<vector<int>> mat = {
        {6, 5, 4},
        {1, 2, 5},
        {7, 9, 7}};
    vector<int> ans = soln(mat, n);
    cout << "Ans: " << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
