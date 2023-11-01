// input: nums=[2,7,11,15], target=9
// output: [0,1]

#include <bits/stdc++.h>
using namespace std;

// brute force- T.C:O(n^2) || S.C:O(1)
// i k 0th position e rakhbo, and j k i+1 theke n-1 obdhi traverse koria
// check korbo whether a[i]+a[j]==target kina then return {i,j} else
// i k increment korbo and repeat the same process
// vector<int> result(int a[], int target, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (a[i] + a[j] == target)
//             {
//                 return {i, j};
//             }
//         }
//     }
// }

// Two-pass Hash Table- T.C:O(N) || S.C:O(N)
// it's same as one pass just the differnece is the elements are stored before continuing the main process
vector<int> result(int arr[], int target, int n)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];
        if (mpp.count(complement))
        {
            return {mpp[complement], i};
        }
    }
    return {};
}

// One-pass Hash Table- T.C:O(N) || S.C:O(N)
// i k iterate korabo and ith element r time e check korbo target-a[i] hast table e present ache kina jodi na
// thake then (a[i],i) r shape e hash table e store kore debo r jodi target-a[i] hash table e present thake then
// i,khuje paoa element r index return korbo
// vector<int> result(int arr[], int target, int n)
// {
//     unordered_map<int, int> mpp;
//     for (int i = 0; i < n; i++)
//     {
//         int complement = target - arr[i];
//         if (mpp.count(complement)) // mpp.count() returns 1 if the element is present in the mpp
//         {
//             return {mpp[complement], i};
//         }
//         mpp[arr[i]] = i; // it stores like (a[i],i) this
//     }
//     return {};
// }

int main()
{
    int a[] = {2, 7, 11, 15}, target = 18, n = 4;

    vector<int> v;
    v = result(a, target, n);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}