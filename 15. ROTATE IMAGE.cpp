// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

#include <bits/stdc++.h>
using namespace std;

// brute force approach is to create another same sized 2d matrix and put the first row as the first column and so on now the new created matrix is the result n^2 and n^2

// in optimal approach we have to do it in place so that it does not take any extra place.
// first step is to transpose the matrix
// second step is to reverse each row of that transposed matrix
// transpose means row elements gets converted into column elements and vice verca
// N^2 and 1

void soln(vector<vector<int>> &matrix)
{
    int n = matrix.size(); // it states the amount of rows in the matrix

    // now transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reversing each rows
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << "Ans: " << endl;
    soln(matrix);
    for (auto it : matrix)
    {
        for (int i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}