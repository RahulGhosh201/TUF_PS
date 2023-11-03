// ip : 102, 4, 100, 1, 101, 3, 2
// op :4
// explaination: length of 1,2,3,4 is 4

#include <bits/stdc++.h>
using namespace std;

// naive approach is to sort the array then return the maximum consecutive sequence
// nlongn and 1
// int soln(int arr[], int n)
// {
//     int maxi = INT_MIN, cnt = 0;
//     sort(arr, arr + n);
//     for (int i = 0; i < n; i++)
//     {
//         if (i > 0 && (arr[i - 1] + 1) == arr[i])
//             cnt++;
//         // else
//         // cnt = 1;
//         maxi = max(maxi, cnt);
//     }
//     return maxi;
// }

int soln(vector<int> &nums)
{
    set<int> hashSet;
    for (int num : nums)
    {
        hashSet.insert(num);
    }

    int ans = 0;
    for (int num : nums)
    {
        if (!hashSet.count(num - 1))
        {
            int currNum = num, currStreak = 1;
            while (hashSet.count(currNum + 1))
            {
                currNum += 1;
                currStreak += 1;
            }
            ans = max(ans, currStreak);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 9, 3, 10, 4, 5, 20, 2};
    int ans = soln(arr);
    cout << "Ans: " << ans << endl;
    return 0;
}