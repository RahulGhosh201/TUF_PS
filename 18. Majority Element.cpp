// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

#include <bits/stdc++.h>
using namespace std;

// in the brute force approach we can create a map and it will take n and n but it will take extra space

// optized approach is using Moore voting algo i.e.
// initially count=0,element=0 then in a linear for loop, if count=0 then element=a[i]
// and if a[i]=element then count+=1 else count-=1

int soln(vector<int> nums)
{
    int count = 0, ele = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            ele = nums[i];
        }
        if (nums[i] == ele)
        {
            count += 1;
        }
        else
        {
            count -= 1;
        }
    }
    return ele;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    int ans = soln(nums);
    cout << "Ans: " << ans << endl;
}