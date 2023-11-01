// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

#include <bits/stdc++.h>
using namespace std;
// first ask the interviewer whether all the intervals given in sorted order or not

// brute force approach is to see for each interval if there is another that can be merged with it and it willl take n^2 time

// now the optimized appproach is to sort all the elements and then make pair of the
// for merging two pair we will compare the left most element of both the pair and smallest one will get selected
//     and we will compare the right most element of both the pair and largest one will get selected
// nlogn and n

vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergedIntervals;
    if (intervals.size() == 0)
    {
        return mergedIntervals; // if there is no initervals then return an empty vector of vector
    }
    sort(intervals.begin(), intervals.end()); // sort all the intervals
    // creating a temporary interval and put the first interval init
    vector<int> tempInteval = intervals[0];

    for (auto it : intervals)
    {
        if (it[0] <= tempInteval[1])
        {                                                // we are checking if the interval can be merged
            tempInteval[1] = max(it[1], tempInteval[1]); // then merge it
        }                                                // otherwise push it in the ans
        else
        {
            mergedIntervals.push_back(tempInteval);
            tempInteval = it;
        }
    }
    mergedIntervals.push_back(tempInteval);
    return mergedIntervals;
}

int main()
{
    vector<vector<int>> intervals = {{6, 8}, {1, 9}, {2, 4}, {4, 7}, {15, 18}};
    vector<vector<int>> merged = overlappedInterval(intervals);

    cout << "The Merged Intervals are: ";
    for (const vector<int> &interval : merged)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}