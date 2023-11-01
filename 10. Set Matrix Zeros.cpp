// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

#include <bits/stdc++.h>
using namespace std;

// brute force approach
// first we will ask the interviewer if all the elements present in the matrix >=0 or not then
// the row and column that has to be o is annoted as -1 though don't change the 0's as it can affect the other columns and rows.
// now whereever we find a -1 we make it as 0
// complexity is (n*m)(n+m) and O(1)

// now for the optimized approach we will take two dummy arrays of number of rows and columns sized
// now in which a 0 exists that indexed row or column will be assigned 0
// then assign the 0s according to this dummy arrays
// complexity will be (n*m + n*m) and O(1)

// now the most optimized approach is to take the first row as the column dummy array and first column as the row dummy array
void setZeroes(vector<vector<int>> &matrix)
{
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
    // matrix.size() is no of rows
    // matrix[0].size() is no of columns

    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
        { // we are saying that if the first column contains any 0 then col0=0
            col0 = 0;
        }
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0; // kono jaygay 0 khuje pelei sei row or column r top most element k 0 kore debo
            }
        }
        // now linearly traversing backwards
        for (int i = rows - 1; i >= 0; i++)
        {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1},
                                  {1, 0, 1},
                                  {1, 1, 1}};

    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}