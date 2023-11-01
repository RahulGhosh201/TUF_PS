#include <bits/stdc++.h>
using namespace std;

// as a naive approach we can use O(n^2)
// or we can use sort the array and find return a[i] when a[i]=a[i+1] that will take nlogn time

// hashing approach it's complexity is O(n) || O(n) as we are taking an extra hash table
// int duplicate(int a[], int n)
// {
//     map<int, int> m;
//     for (int i = 0; i < n; i++)
//     {
//         m[a[i]]++;
//     }
//     for (auto it : m)
//     {
//         if (it.second > 1)
//         {
//             return it.first;
//         }
//     }
// }

// the most optimized approach is linked list cycle method with the help of tortoise method which contains
// slow and fast pointers
// The slow pointer always moves to the next element where as the always moves to the second next element
// now at which element the slow and fast pointer meets for the swcond time is the result of that problem
// the linked list cycle method is as follows->
// the traversal will start from the first element and it will next go to a[i]th element and in this way it will create a cycle
// O(n) || O(1)

int duplicate(vector<int> &arr)
{
    int slow = arr[0]; // as we know it starts from 0th index
    int fast = arr[0]; // as we know it starts from 0th index
    do
    {
        slow = arr[slow];      // slow pointer is moving by 1 step
        fast = arr[arr[fast]]; // fast pointer is moving by 2 step
    } while (slow != fast);
    // after the slow and fast pointer meet with each other the control of the program will come outside of the while loop and
    //  now slow pointer stays at that index
    fast = arr[0]; // making the fast pointer at start again
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast]; // this time both the slow and fast pointer will take one step at a time
    }
    return slow;
}

int main()
{
    vector<int> a = {1, 2, 5, 2};
    int ans = duplicate(a);
    cout << "Ans: " << ans << endl;
    return 0;
}