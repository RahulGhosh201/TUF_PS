// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

#include <bits/stdc++.h>
using namespace std;

// we can use kadane approach using n^2

// optimized approach:
//  initially l=0, r=0, len=0, and create a set
//  now if a[l]!=a[r]
//  r++, len=r-l+1, and insert a[r] in the set
//  if a[r] is already in the set then remove a[l] from set and l++, len=r-l+1, and insert a[r] in the set
//  this process continues till the end of the string and return len as ans
// O(2n) and O(n)

#include <bits/stdc++.h>
using namespace std;

int soln(string str)
{
    vector<int> m(256, -1);
    int l = 0, r = 0, len = 0;
    int n = str.size();
    while (r < n)
    {
        if (m[str[r]] != -1)
            l = max(m[str[r]] + 1, l);
        m[str[r]] = r;
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}

int main()
{
    string str = "abacdcdab";
    int ans = soln(str);
    cout << "Ans: " << ans << endl;
    return 0;
}