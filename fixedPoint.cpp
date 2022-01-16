/*
Fixed Point
You are given an array 'ARR' of ‘N’ distinct integers sorted in ascending order. You need to find the smallest fixed point in the array, such that the value stored at a particular index is equal to the index. That means 'ARR[i]' == 'i', where 'ARR[i]' denotes element at the the 'i'th index.
Note:
 1.Note that the array contains negative integers as well. 

2. Also, note that every array contains a single fixed point.
Example :
Given Array = [-1, 1, 3, 5]
In the above example 'ARR[1]' == 1, so you need to return 1.
Input Format:
The first line contains an integer ‘T’ which denotes the number of test cases. 

The first line of each test case contains a single integer ‘N’, denoting the size of the input array.

The next line contains ‘N’ space-separated integers denoting the elements of the array.
Output Format:
For each test case, you need to return a single integer denoting the index or value at which 'ARR[i]' == 1. In case no such value exists, return -1.

Print the output of each test case in a separate line.
Note:
You don’t need to print anything; It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <=  N  <= 10000
-10^9 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes element at the the 'i'th index.

Time limit: 1 sec
Sample Input 1:
2
4
-1 1 3 5
3
1 2 3
Sample Output 1:
1
-1
Explanation of Sample Output 1:
In test case 1, 'ARR[1]' == 1, so you need to return 1.

In test case 2, No such value present, so you need to return -1.
Sample Input 2:
2
4
-1 0 2 4
5
-2 -1 0 1 2
Sample Output 2:
2
-1
Explanation of Sample Output 2:
In test case 1, 'ARR[2]' == 2, so you need to return 2.

In test case 2, No such value present, so you need to return -1.

*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
int equalIndex(vector<int> &arr, int n)
{
    // Write your code here.
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == i)
            return i;
    }

    return -1;
}

class Runner
{
    int t;
    vector<vector<int>> arr;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            vector<int> temp(n);
            for (int i = 0; i < n; i++)
            {
                cin >> temp[i];
            }
            arr.push_back(temp);
        }
    }

    void execute()
    {
        vector<vector<int>> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            int n = arrCopy[i].size();
            int ans = equalIndex(arrCopy[i], n);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int n = arr[i].size();
            int ans = equalIndex(arr[i], n);
            cout << ans << endl;
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
