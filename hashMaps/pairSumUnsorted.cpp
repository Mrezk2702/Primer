// tryouts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

int Left = 0;
int Right = 0;
int sad = 0;


pair<int,int>  PairSum(const vector<int>& arr, int target)
{
    pair<int, int> retVal = {-1,-1};
    unordered_map<int, int>seen;
    int comp;
    for(int i=0;i<arr.size();i++)
  {
        int complement = target - arr[i];
        if (seen.count(complement))
        {
            retVal = {seen[complement],i};
            break;
        }
        seen[arr[i]] = i;

    }
    return retVal;
}
int main()
{
    vector<int> arr = { 2,7,6,5,4 };
    int target = 10;

    pair<int, int>x = PairSum(arr, 10);
    if (x.first == -1 && x.second == -1)
    {
        cout << "Not found";
    }
    else
    {
        cout << "Target is found at index: " << x.first << " and " << x.second;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
