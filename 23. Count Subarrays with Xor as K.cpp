// Input : arr[] = {4, 2, 2, 6, 4}, m = 6
// Output : 4
// Explanation : The subarrays having XOR of
//               their elements as 6 are {4, 2},
//               {4, 2, 2, 6, 4}, {2, 2, 6},
//                and {6}

#include <bits/stdc++.h>
using namespace std;

int soln(int arr[], int n, int m)
{
}

int main()
{
    int arr[] = {4, 2, 2, 6, 4}, m = 6;
    int ans = soln(arr, 5, m);
    cout << "Ans: " << ans << endl;
    return 0;
}