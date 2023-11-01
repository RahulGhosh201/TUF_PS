// Input: ar1[] = {10}, ar2[] = {2, 3}
// Output: ar1[] = {2}, ar2[] = {3, 10}

// Input: ar1[] = {1, 5, 9, 10, 15, 20}, ar2[] = {2, 3, 8, 13}
// Output: ar1[] = {1, 2, 3, 5, 8, 9}, ar2[] = {10, 13, 15, 20}

#include <bits/stdc++.h>
using namespace std;

// using a brute force approach for complexity of nlogn and space
// complexity of O(n1+n2) we can do is create a n1+n2 sized third array and insert all the elements
// in this array from ar1 and ar2. Now using sort function sort that array
// in nlogn time and now again store the ar1 and ar2 accordingly
void soln(int ar1[], int ar2[], int n1, int n2)
{
    int temp[n1 + n2], k = 0;
    for (int i = 0; i < n1; i++)
    {
        temp[k++] = ar1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        temp[k++] = ar2[i];
    }

    sort(temp, temp + k);
    for (int i = 0; i < n1; i++)
    {
        ar1[i] = temp[i];
    }
    for (int i = n1; i < n1 + n2; i++)
    {
        ar2[i] = temp[i];
    }

    for (int i = 0; i < n1; i++)
    {
        cout << ar1[i] << " ";
    }
    for (int i = 0; i < n2; i++)
    {
        cout << ar2[i] << " ";
    }
    cout << endl;
}
// gap method is more optimized
int main()
{
    int ar1[] = {10}, ar2[] = {2, 3};
    int n1 = 1, n2 = 2;
    soln(ar1, ar2, n1, n2);
}