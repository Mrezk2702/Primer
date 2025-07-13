// tryouts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

using namespace std;




void inplaceZeroTracking(vector<vector<int>> matrix)
{
    bool zeroRow = false;
    bool zeroCol = false;
    int rsize = matrix.size();
    int csize = matrix[0].size();
    for (int i = 0;i < csize;i++)
    {
        if (matrix[0][i] == 0)
        {
            zeroRow = true;
        }
    }
    for (int i = 0;i < rsize;i++)
    {
        if (matrix[i][0])
        {
            zeroCol = true;
        }
    }
     
    for (int r = 1;r < rsize;r++)
    {
        for (int c = 1;c < csize;c++)
        {
            if (matrix[r][c] == 0)
            {
                matrix[r][0] = 0;
                matrix[0][c] = 0;
            }
        }
    }

    for (int r = 1;r < rsize;r++)
    {
        for (int c = 1;c < csize;c++)
        {
            if (matrix[0][c] == 0 || matrix[r][0] == 0)
            {
                matrix[r][c] = 0;
            }
        }
    }

    if (zeroRow)
    {
        for (int i = 0;i < csize;i++)
        {
            matrix[0][i] = 0;
        }
    }
    if (zeroCol)
    {
        for (int i = 0;i < rsize;i++)
        {
            matrix[i][0] = 0;
        }

    }
    for (int r = 0;r < rsize;r++)
    {
        for (int c = 0;c < csize;c++)
        {
            cout << matrix[r][c] << " ";
        }
        cout << endl;

    }
    cout << endl << endl;

    


}



int main()
{
    vector<vector<int>> arr = { 
     {1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1} };

    const int rsize = arr[0].size();
    const int csize = arr.size();
    for (int r = 0;r < rsize;r++)
    {
        for (int c = 0;c < csize;c++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;

    }
    cout << endl << endl;
    inplaceZeroTracking(arr);



   
  
    return 0;
}