// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
#include <bits/stdc++.h>
using namespace std;

// brute force approach is O(n^3)
// the first loop will traverse from 0 to n - 1
// 2nd loop will traverse from i to n-1
// 3rd loop will traverse from i to j
// and then calcuate the sum in this position
// now outside the 3rd loop maxi=max(sum,maxi)
// maxi will be result

// we can optimie it to o(n^2)
// by omitting the third loop
//  the first loop will traverse from 0 to n - 1
// sum=0
//  2nd loop will traverse from i to n-1
// sum+=a[j]
// maxi = max(sum, maxi)
// maxi will be result

// linear soln is the kadane's algo
// initially sum=0, maxi=a[i] or INT_MIN
// now we have to traverse the whole array and sum+=arr[i]
// now if sum < 0 then sum = 0 and maxi=max(sum,max)
// maxi is the ans

int soln2(int nums[])
{
    int sum = 0, maxi = INT_MIN;
    for (int i = 0; i < 9; i++)
    {
        sum += nums[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int main()
{
    // vector<int> nums;
    // nums.push_back(-2);
    // nums.push_back(1);
    // nums.push_back(-3);
    // nums.push_back(4);
    // nums.push_back(-1);
    // nums.push_back(2);
    // nums.push_back(1);
    // nums.push_back(-5);
    // nums.push_back();
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = soln2(nums);
    cout << "Ans: " << ans << endl;
    return 0;
}
