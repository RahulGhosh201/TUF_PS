// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
#include <bits/stdc++.h>
using namespace std;

// Recursive approach// T.C : O(2^n) || S.C:O(2^n) space complexity te exponential lagche karon it will require stack space in recursion
//  we have to create a recursive tree and there we will see that the next bottom element's index is i+1,j and right element's index i,j+1
//   and this way we will create a recursive tree if we get succedded to go to the m-1,n-1 index in this way by a tree branch that means that is one of the way and the total ways will be counted as
//   the result
//  As we know this is a recursive approach and also we know that always the a recursive approach contains a base case
//  we can say i<=m and j<=n is one of the base cases
//  another base case is when i==m-1 and j==n-1

// int countPaths(int m, int n)
// {
//     if (m == 1 || n == 1)
//     {
//         return 1;
//     }
//     return countPaths(m - 1, n) + countPaths(m, n - 1);
// }

// Dynamic programming paproach T.C:O(m*n)||S.C:O(m*n)
//  it means repeating the past like recursion but without actually computing it and that's why dp always takes less time than recursion
int countPaths(int m, int n, int DP[4][4])
{
    if (m == 1 || n == 1)
    {
        return DP[m][n] = 1;
    }
    if (DP[m][n] == 0)
    {
        DP[m][n] = countPaths(m - 1, n, DP) + countPaths(m, n - 1, DP);
    }
    return DP[m][n];
}

int main()
{
    int DP[4][4] = {0};
    memset(DP, 0, sizeof(DP));
    cout << countPaths(3, 3, DP);

    // cout << "Ans: " << countPaths(3,3) << endl;
    return 0;
}