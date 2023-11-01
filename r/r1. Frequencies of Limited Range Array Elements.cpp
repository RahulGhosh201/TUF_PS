// Input:
// N = 5
// arr[] = {2, 3, 2, 3, 5}
// P = 5
// Output:
// 0 2 2 0 1
// Explanation:
// Counting frequencies of each array element
// We have:
// 1 occurring 0 times.
// 2 occurring 2 times.
// 3 occurring 2 times.
// 4 occurring 0 times.
// 5 occurring 1 time.

#include <bits/stdc++.h>
using namespace std;

void soln(vector<int> &arr, int n, int p)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = m[i + 1];
    }
}

int main()
{
    vector<int> arr = {2, 3, 2, 3, 5};
    int n = arr.size(), p = 5;
    soln(arr, n, p);
    cout << "Ans: ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}