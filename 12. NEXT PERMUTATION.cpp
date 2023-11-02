// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]

#include <bits/stdc++.h>
using namespace std;

// we can use next_permutation like this
// void nextPermutation(vector<int>& arr)
// {
//     next_permutation(arr.begin(),arr.end());
// }

// brute force approach is to generate all the combos and then linearly iterate and find the given combo and return the next combo as the answer
// but it will take n!*n time as there will be n! combos and each combo has n elements init

// optimal approach takes linear time
// algorithm used here-
// step-1. iterate from back and make index1=i when a[i]<a[i+1]
// step-2. iterate from back again make index2=i when a[index2]>a[index1]
// step-3. swap(a[index1],a[index2])
// step-4. reverse(index<->last)
// when the given input is in dictionary order meaning it contains a peak init, we will follow this algo
// and if the given input does not contain a peak i.e.5 4 3 2 1 then we will just reverse it to get the result

void nextPermutation(vector<int> &nums)
{
    int n = nums.size(), k, l;
    // k is the break point
    //  now we are trying to iterate from back and make index1=i when a[i]<a[i+1]
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
        {
            break;
        }
    } // now we will check whether we found a peak element or not if not found then we will just reverse it
    if (k < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        // iterate from back again make index2=i when a[index2]>a[index1]
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }

        // swap(a[index1],a[index2])
        swap(nums[k], nums[l]);
        // reverse(index<->last)
        reverse(nums.begin(), nums.end());
    }
}

int main()
{
    vector<int> v = {1, 2, 3};
    nextPermutation(v);
    cout << "Ans: ";
    reverse(v.begin(), v.end());
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}