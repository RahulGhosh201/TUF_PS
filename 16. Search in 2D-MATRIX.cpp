// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

#include <bits/stdc++.h>
using namespace std;

// brute force approach is to do a linear search in n*m

// for the optimized approach we can see that each row is sorted , so we will go to each row and do a binary search. it will take nlogm
// int binarySearch(vector<int> arr, int k)
// {
//     int n = arr.size();
//     int l = 0, r = n - 1;
//     while (l <= r)
//     {
//         int m = l + (r - l) / 2;
//         if (arr[m] == k)
//         {
//             return 1;
//         }
//         if (arr[m] < k)
//         {
//             l = m + 1;
//         }
//         else
//         {
//             r = m - 1;
//         }
//     }
//     return 0;
// }

// bool searchMatrix(vector<vector<int>> matrix, int k)
// {
//     int n = matrix.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (binarySearch(matrix[i], k))
//         {
//             return 1;
//         }
//     }
//     return 0;
// }

// most optimized approach-
// we will take a pointer which will point to the last element of the first row and then if target>element then target will move downwards and if target<element then target will move to the left
// now if the element is not present then it will move out of bound of the matrix
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return 1;
        }
        if (matrix[i][j] > target)
        {
            j--; // left side e move korche
        }
        else
        {
            i++; // downward move korche
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 59;
    bool ans = searchMatrix(matrix, target);
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}