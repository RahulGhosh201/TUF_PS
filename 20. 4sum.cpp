// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

#include <bits/stdc++.h>
using namespace std;

// approach-> sort+3 ptr+binary search+hash set takes n^3logn
// atfirst sort the given array then take 3 ptr i=0,j=i+1,k=j+1 now find target-(arr[i]+arr[j]+arr[k])
// in the left side of the pointers using binary search if found push this index combination and now we
// will have some combinations now push this combinations into a hash set to get the unique cmombinations

// optimized approach-> sort+ 2 ptr + right and left ptr +binary search
// int his process first we have to sort the array then take i=0, j=i+1 initially and left=j+1 right=n-1 initially
// now a[i]+a[j]+a[left]+a[right]==target hole combo pachhi if < target then left++ and if > target then right--
// n^3

vector<vector<int>> soln(vector<int> &arr, int target)
{
    vector<vector<int>> res;
    if (arr.empty())
        return res;
    int n = arr.size();           // number of elements in the array
    sort(arr.begin(), arr.end()); // step-1

    for (int i = 0; i < n; i++)
    { // i is the 1st ptr
        for (int j = i + 1; j < n; j++)
        { // j is the 2nd ptr
            int temp = target - arr[i] - arr[j];
            int left = j + 1, right = n - 1;
            while (left < right)
            {
                int two_sum = arr[left] + arr[right];
                if (two_sum < temp)
                    left++;
                else if (two_sum > temp)
                    right--;
                else
                {
                    vector<int> q(4, 0);
                    q[0] = arr[i];
                    q[1] = arr[j];
                    q[2] = arr[left];
                    q[3] = arr[right];
                    res.push_back(q);
                    while (left < right && arr[left] == q[2]) // processing the duplicates of number 3
                        ++left;

                    while (left < right && arr[right] == q[3])
                        ++right;
                }
            }
            while (j + 1 < n && arr[j + 1] == arr[j])
                ++j;
        }
        while (i + 1 < n && arr[i + 1] == arr[i])
            ++i;
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = soln(arr, target);
    for (auto it : ans)
    {
        for (int num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}