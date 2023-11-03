// Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
// Output: 5
// Explanation: The longest sub-array with elements summing up-to 0 is {-2, 2, -8, 1, 7}

// Input: arr[] = {1, 2, 3}
// Output: 0
// Explanation: There is no subarray with 0 sum

#include <bits/stdc++.h>
using namespace std;

// naive soln is to generate all the sub arrays that will give the result nad then return the maximum lengthed sub array's length

// optimized approach is use hashing nlogn and n

int maxLen(int arr[], int n)
{
    unordered_map<int, int> m;
    int maxi = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (m.find(sum) != m.end())
            {                                 // if the sum is found in the map or not
                maxi = max(maxi, i - m[sum]); // m[sum] holo previously jekhane sum paoa gechilo tar index
            }
            else
            {
                m[sum] = i;
            }
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = maxLen(arr, n);
    cout << "Ans: " << ans << endl;
    return 0;
}