/*
Alex has a computer with ‘K’ memory spaces. He has a list of ‘N’ different document downloads that he would like to do, each of which consumes some unique memory usage. He also has ‘M’ computer games, each of which consumes some unique memory usage. His computer can allow at most one download and at most one game to run simultaneously, provided that the sum of memory usages doesn’t exceed ‘K’. Alex wants to play at most one game and complete at most one download so that the total memory usage is maximum.
Given a list ‘download’ and a list ‘game’, help Alex find out the number of pairs of downloads and games such that the sum of memory usages is maximum. It can also be possible that Alex only plays a game or performs a download at a time.
Input Format:
The first line of input contains an integer ‘T’, denoting the number of test cases. Then the test cases follow.

The first line of each test case contains three space-separated integers, ‘N’, ‘M’ and ‘K’, denoting the number of downloads and games and the total memory available, respectively.

The second line of each test case contains  ‘N’ space-separated integers denoting the memory usages of downloads in the array ‘download’.

The third line of each test case contains  ‘M’ space-separated integers denoting the memory usages of games in the array ‘game’.
Output Format:
For each test case, print an array ‘result’, denoting the pairs of downloads and games for maximum memory usage in the following format.
result[i] = [ind1, ind2], where ind1 is the index of the download chosen and ind2 is the index of the game selected. If only one game or one download is chosen, put the other index as ‘-1’. In case no options are available, print ‘-1 -1’.
Note:
You are not required to print the expected output. It has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 10
1 <= N, M <= 10^5
1 <= K <= 10^9
1 <= game[i], download[i] <= 10^6

Time Limit: 1 sec
Sample Input 1:
2
6 7 6
1 7 2 4 5 6
2 3 4 1 5 8 10
4 3 8
2 1 5 9
9 2 4
Sample Output 1:
0 4
2 2
3 0
4 3
5 -1
2 1
Explanation for Sample Input 1:
In test case one, if we check the pairs, we can see that the maximum permitted memory that we can use is 6. The pairs (0, 4), (2, 2), (3, 0), and (4, 3) sum up to 6 memory usages. Also, download number 5 will alone consume 6 memory. So, pair (6, -1) is also valid.
In test case two, the maximum permitted memory usage is 7. Only pair (2, 1) sum up to 7 memory usages.
Sample Input 2:
3
2 3 4
1 3
3 1 10
5 6 2
1 3 5 7 9
1 3 5 7 9 11
1 3 5
3
1 2 3
Sample Output 2:
0 0
1 1
0 0
0 1
*/

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> optimizeMemoryUsage(int k, vector<int> download, vector<int> game)
{
    int n = download.size();
    int m = game.size();
    int max_usage = 0;

    // Finding the maximum memory usage we can perform
    for (int i = 0; i < n; i++)
    {
        if (download[i] <= k)
        {
            max_usage = max(max_usage, download[i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        // Checking the corner case of only choosing game or download
        if (game[i] <= k)
        {
            max_usage = max(max_usage, game[i]);
        }

        // Checking all pairs
        for (int j = 0; j < n; j++)
        {
            if (game[i] + download[j] <= k)
            {
                max_usage = max(max_usage, game[i] + download[j]);
            }
        }
    }

    vector<vector<int>> result;

    // Finding the optimal pairs
    for (int i = 0; i < n; i++)
    {
        if (download[i] == max_usage)
        {
            vector<int> pr{i, -1};
            result.push_back(pr);
        }
    }
    for (int i = 0; i < m; i++)
    {
        // Checking the corner cases
        if (game[i] == max_usage)
        {
            vector<int> pr{-1, i};
            result.push_back(pr);
        }

        // Checking all pairs
        for (int j = 0; j < n; j++)
        {
            if (game[i] + download[j] == max_usage)
            {
                vector<int> pr{j, i};
                result.push_back(pr);
            }
        }
    }

    // If no suitable pair found
    if (result.size() == 0)
    {
        vector<int> pr{-1, -1};
        result.push_back(pr);
    }

    // Return the array
    return result;
}

class Runner
{
    int t;

    vector<vector<int>> game;
    vector<vector<int>> download;
    vector<int> kArr;

public:
    void takeInput()
    {

        cin >> t;
        kArr.resize(t);
        download.resize(t);
        game.resize(t);

        for (int tc = 0; tc < t; tc++)
        {
            int n, m, k;
            cin >> n >> m >> k;
            kArr[tc] = k;

            download[tc].resize(n);
            game[tc].resize(m);

            for (int i = 0; i < n; i++)
            {
                cin >> download[tc][i];
            }
            for (int i = 0; i < m; i++)
            {
                cin >> game[tc][i];
            }
        }
    }
    /*
    vector<vector<int>> getCopy()
    {
        vector<vector<int>> arrCopy = arr;


        return arrCopy;
    }
    */
    void execute()
    {
        vector<vector<int>> gameCopy = game;
        vector<vector<int>> downloadCopy = download;
        vector<int> kArrCopy = kArr;

        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> ans = optimizeMemoryUsage(kArrCopy[i], downloadCopy[i], gameCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> ans = optimizeMemoryUsage(kArr[i], download[i], game[i]);

            sort(ans.begin(), ans.end());
            for (int j = 0; j < ans.size(); j++)
                cout << ans[j][0] << " " << ans[j][1] << endl;
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
