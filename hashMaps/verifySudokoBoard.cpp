#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int Left = 0;
int Right = 0;
int sad = 0;


bool verifySudokuBoard(vector<vector<int>> board)
{

    unordered_set<int> row[9];
    unordered_set<int> col[9];
    unordered_set<int> grid[3][3];
    for (int r=0;r<9;r++)
    {
        for (int c=0;c<9;c++)
        {
            int num = board[r][c];
            /*check if box is empty*/
            if (num == 0)
            {
                continue;

            }
            if (row[r].count(num) || col[c].count(num) || grid[r / 3][c / 3].count(num))
            {
                return false;
            }
            else
            {
                row[r].insert(num);
                col[c].insert(num);
                grid[r / 3][c / 3].insert(num);

            }

        }
    }
    return true;
}



int main()
{
    vector<vector<int>> arr = { 
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    bool res=verifySudokuBoard(arr);

    if (res)
    {
        cout << "board valid";
    }
    else
    {
        cout << "board not valid";
    }
   
  
    return 0;
}