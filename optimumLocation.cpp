/*
Optimum Location
You are given a straight line on a 2D plane in the form of (ax + by + c = 0) and an array of points of the form (Xi, Yi). Your task is to find a point on the given line for which the sum of distances from this point to the given array/list of points is minimum.
For Example :
optimum_location_example

Here the equation for the given line is x - y = 0, i.e. a = 1, b = -1 and c = 0. 
There are two points, i.e. (-1, 1) and (1, -1).

So, the point on the line that has minimum distances from the points is (0, 0). The sum of distances is sqrt(1 + 1) + sqrt(1 + 1) = sqrt(2) + sqrt(2) = 2.83 (rounding to 2 decimal digits).
Input format :
The first line contains an integer 'T', which denotes the number of test cases or queries to be run. Then, the T test cases follow.

The first line of each test case contains three space-separated integers denoting a, b and c, respectively, representing the equation of the given line as mentioned above.

The second line of each test case contains a single integer N, denoting the number of coordinates.

Then N lines follow. Each line contains two space-separated integers denoting the x-coordinate and the y-coordinate of the point, respectively.
Output format :
For each test case, print the minimum possible distance.
Your answer will be considered correct if its absolute or relative error doesn’t exceed 10^-6.

Output for each test case will be printed in a separate line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 100
1 <= N <= 3000
-100 <= a, b, c, points[i].x, points[i].y <= 100 and (a != 0, b != 0) 

Time limit: 1 second
Sample Input 1:
2
3 2 5
5
1 -1
2 3
4 4
5 -1
3 2
3 1 -4
4
1 2
4 -2
5 -3
7 -6
Sample Output 1:
24.94
15.32
Explanation for sample 1:
For the first test case, the optimum point is (-0.72, -1.42). 

For the second test case, the optimum point is (2.29, -2.87).
Sample Input 2:
2
-1 2 -4
4
-2 1
2 3
0 2
-4 0
2 -5 4
5
2 1
7 -9
4 -3
-5 2
8 -6
Sample Output 2:
8.94
33.83
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

#include <cmath>

double findSumOfDistances(int a, int b, int c, vector<vector<int>> &points, int n, double x)
{

    double sum = 0;

    // The Y-Coordinate of the point on the line corresponding to x.
    double y = -(x * a + c) / b;

    for (int i = 0; i < n; i++)
    {
        double distance = (x - points[i][0]) * (x - points[i][0]) + (y - points[i][1]) * (y - points[i][1]);
        sum = sum + sqrt(distance);
    }

    return sum;
}

double optimumDistance(int a, int b, int c, vector<vector<int>> &points, int n)
{
    // Write your code here
    double low = -1e6;
    double high = 1e6;

    // Run the loop until the difference between low and high is negligible.
    while ((high - low) > 1e-6)
    {

        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;

        double distance1 = findSumOfDistances(a, b, c, points, n, mid1);
        double distance2 = findSumOfDistances(a, b, c, points, n, mid2);

        if (distance1 < distance2)
        {
            high = mid2;
        }
        else
        {
            low = mid1;
        }
    }

    // The X-Coordinate of the optimum point.
    double x = (low + high) / 2;

    return findSumOfDistances(a, b, c, points, n, x);
}

double findSumOfDistancesTest(vector<int> &line, vector<vector<int>> &points, double x)
{

    double sum = 0;

    // The Y-Coordinate of the point on the line corresponding to x.
    double y = -(x * line[0] + line[2]) / line[1];

    int n = points.size();

    for (int i = 0; i < n; i++)
    {
        double distance = (x - points[i][0]) * (x - points[i][0]) + (y - points[i][1]) * (y - points[i][1]);
        sum = sum + sqrt(distance);
    }

    return sum;
}

double optimumDistanceTest(vector<int> &line, vector<vector<int>> &points)
{

    double low = -1e6;
    double high = 1e6;

    // Run the loop until the difference between low and high is negligible.
    while ((high - low) > 1e-6)
    {

        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;

        double distance1 = findSumOfDistancesTest(line, points, mid1);
        double distance2 = findSumOfDistancesTest(line, points, mid2);

        if (distance1 < distance2)
        {
            high = mid2;
        }
        else
        {
            low = mid1;
        }
    }

    // The X-Coordinate of the optimum point.
    double x = (low + high) / 2;

    return findSumOfDistancesTest(line, points, x);
}

class Runner
{
    int t;

    vector<vector<int>> lines;
    vector<vector<vector<int>>> pointsArr;

public:
    void takeInput()
    {

        cin >> t;

        lines.resize(t);
        pointsArr.resize(t);

        for (int c = 0; c < t; c++)
        {

            lines[c].resize(3);
            cin >> lines[c][0] >> lines[c][1] >> lines[c][2];

            int n;
            cin >> n;

            vector<vector<int>> temp(n, vector<int>(2));

            for (int i = 0; i < n; i++)
            {
                cin >> temp[i][0] >> temp[i][1];
            }

            pointsArr[c] = temp;
        }
    }

    void execute()
    {

        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> copyPoint = pointsArr[i];

            optimumDistance(lines[i][0], lines[i][1], lines[i][2], copyPoint, copyPoint.size());
        }
    }

    void executeAndPrintOutput()
    {

        for (int i = 0; i < t; i++)
        {
            vector<int> line = lines[i];

            double userOutput = optimumDistance(line[0], line[1], line[2], pointsArr[i], pointsArr[i].size());
            double testerOutput = optimumDistanceTest(line, pointsArr[i]);

            double error = abs(userOutput - testerOutput) / max(1.0, abs(testerOutput));

            if (error <= 1e-6)
            {
                cout << "Correct"
                     << "\n";
            }
            else
            {
                cout << "Incorrect"
                     << "\n";
            }
        }
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Runner runner;

    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}