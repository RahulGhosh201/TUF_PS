// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
#include <bits/stdc++.h>
using namespace std;

// brute force- O(N^2) || O(1)
// int res(int arr[], int n)
// {
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] > 2 * arr[j])
//             {
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

// using merge sort-O(N) || O(N)
void merge(vector<int> &nums, int low, int mid, int high, int &reversePairsCount)
{
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > 2 * (long long)nums[j])
        {
            j++;
        }
        reversePairsCount += j - (mid + 1);
    }
    int size = high - low + 1;
    vector<int> temp(size, 0);
    int left = low, right = mid + 1, k = 0;
    while (left <= mid && right <= high)
    {
        if (nums[left] < nums[right])
        {
            temp[k++] = nums[left++];
        }
        else
        {
            temp[k++] = nums[right++];
        }
    }
    while (left <= mid)
    {
        temp[k++] = nums[left++];
    }
    while (right <= high)
    {
        temp[k++] = nums[right++];
    }
    int m = 0;
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[m++];
    }
}

void mergeSort(vector<int> &nums, int low, int high, int &reversePairsCount)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) >> 1;
    mergeSort(nums, low, mid, reversePairsCount);
    mergeSort(nums, mid + 1, high, reversePairsCount);
    merge(nums, low, mid, high, reversePairsCount);
}

int reversePairs(vector<int> &nums)
{
    int reversePairsCount = 0;
    mergeSort(nums, 0, nums.size() - 1, reversePairsCount);
    return reversePairsCount;
}