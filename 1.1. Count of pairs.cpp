// Input: arr[] = {1, 5, 7, -1}, K = 6
// Output:  2
// Explanation: Pairs with sum 6 are (1, 5) and (7, -1).

#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (m.find(sum - arr[i]) != m.end())
        {
            count++;
        }
        m[arr[i]] = i;
    }
    return count;
}

int main()
{
    int arr[] = {1, 5, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;

    cout << "Count of pairs is "
         << getPairsCount(arr, n, sum);
    return 0;
}
