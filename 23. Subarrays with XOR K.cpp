// Sample Input 1:
// 4 2
// 1 2 3 2
// Sample Output 1 :
// 3
// Explanation Of Sample Input 1:
// Input: ‘N’ = 4 ‘B’ = 2
// ‘A’ = [1, 2, 3, 2]

// Output: 3

// Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].
// Sample Input 2:
// 4 3
// 1 2 3 3
// Sample Output 2:
// 4
// Sample Input 3:
// 5 6
// 1 3 3 3 5
// Sample Output 3:
// 2

// we will create a hash map and initialize count and xor as 0;
// now inside the for loop first xor=xor^a[i] then if xor==k then count++ if xor laready present in the hash map then increase it's key value by 1
// else xor!=k then store it in the hash map
// and now return count
// nlogn and n
#include <bits/stdc++.h>
using namespace std;

int soln(vector<int> a, int k)
{
    int xorr = 0, cnt = 0;
    map<int, int> m;
    for (auto it : a)
    {
        xorr ^= it;
        if (xorr == k)
        {
            cnt++;
        }
        if (m.find(xorr ^ k) != m.end())
        {
            cnt += m[xorr ^ k];
        }
        m[xorr] += 1;
    }
    return cnt;
}

int main()
{
    vector<int> v = {1, 2, 3, 2};
    int k = 2;
    int ans = soln(v, k);
    cout << "Ans: " << ans << endl;
    return 0;
}