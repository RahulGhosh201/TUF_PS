// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

#include <bits/stdc++.h>
using namespace std;

// for the brute force approach, suppose j will visit from i+1 to n-1 and find a element which is a[j]>a[i] and we will create
// a variable which will keep track of the maximum difference and that variable is the result.

// optimal soln n and 1

int soln(vector<int> arr)
{
    int miniPrice = INT_MAX, maxPro = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        miniPrice = min(miniPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - miniPrice);
    }

    return maxPro;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int ans = soln(arr);
    cout << "Ans: " << ans << endl;
    return 0;
}