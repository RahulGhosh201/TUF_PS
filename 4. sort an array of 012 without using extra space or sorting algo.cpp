#include <bits/stdc++.h>
using namespace std;

// we can sort the array it's t.c:O(nlogn) || S.c:O(1)
// counting sort: we can count the number of 0's, 1's, 2's and then create another array of same size and print it accordingly it's T.C:O(n)||S.C:O(n)

// Dutch national flag algorithm O(n)||O(1)
// we have to maintain 3 pointers low,mid at start and high at last
// we have to obtain that
// all the elements before low means 0 to low-1 all elements are 0
// all the elements after high means high+1 to n-1 all elements are 2
// all the elements in between low and mid-1 is 1
// now the operation is devided in 3 steps:
// as we already know at start low,mid=0 and high=n-1
// if a[mid]=0 then swap(a[low],a[mid]) and low++, mid++
// if a[mid]=1 then mid++
// if a[mid]=2 then swap(a[mid],a[high]) and high--
void sorting(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {0, 0, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2}, n = 12;
    sorting(arr, n);
    cout << "Ans: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}