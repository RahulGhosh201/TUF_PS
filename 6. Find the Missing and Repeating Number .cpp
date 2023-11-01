// Input: arr[] = {3, 1, 3}
// Output: Missing = 2, Repeating = 3
// Explanation: In the array, 2 is missing and 3 occurs twice

// Input: arr[] = {4, 3, 6, 2, 1, 1}
// Output: Missing = 5, Repeating = 1

#include <bits/stdc++.h>
using namespace std;

// brute force-O(n)||O(n)
// hash map used for repeating element
// a temporary visited array is used to find the missing element
// void missingAndRepeating(int arr[], int n)
// {
//     int repeating = 0, missing = 0;
//     map<int, int> m;
//     for (int i = 0; i < n; i++)
//     {
//         m[arr[i]]++;
//     }
//     for (auto it : m)
//     {
//         if (it.second > 1)
//         {
//             repeating = it.first;
//         }
//     }
//     int temp[n + 1] = {0};
//     for (int i = 0; i < n + 1; i++)
//     {
//         temp[arr[i]] = 1;
//     }
//     for (int i = 0; i < n + 1; i++)
//     {
//         if (temp[i] == 0)
//         {
//             missing = i;
//         }
//     }
//     cout << "Missing: " << missing << " Repeating: " << repeating << endl;
// }

// mathematical approach:O(n)||O(1)
//  s^2=x^2-y^2 and s=x-y
//  so s^2/s=x+y now from x+y and x-y we can determine x and y
//  x is missing number and y is repeating number
// void missingAndRepeating(int arr[], int n)
// {
//     int s = abs((n * (n + 1)) / 2);//x-y
//     int sq = abs((n * (n + 1) * (2 * n + 1)) / 6);//x^2-y^2=(x+y)(x-y)
//     int sum = sq / s;//x+y
//     int missing = (sum + s) / 2;//x
//     int repeating = sum - missing;//y
//     cout << "Missing: " << missing << " Repeating: " << repeating << endl;
// }

void missingAndRepeating(int arr[], int n)
{
}

int main()
{
    int arr[] = {3, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    missingAndRepeating(arr, n);
    return 0;
}