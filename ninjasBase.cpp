/*
Ninja’s Base
One day Ninja asks for one day's leave from his trainer. His trainer agrees with him only if he would complete a task. The task is that Ninja has to find the smallest 'NINJA BASE' of a number ‘N’. We call ‘B >= 2’ a ‘NINJA BASE’, if all digits of ‘N’ base ‘B’ can be written as ‘1s’.
Example :
Suppose given number is ‘13’ so we return ‘3’ as the answer as we can write 13 = 3 ^ 2 + 3 ^ 1 + 3 ^ 0. '3' is the smallest number 'B for which 13 base 'B' is ‘1 1 1’. So, the 'NINJA BASE' of 'N' = 13 is 3.
Given number 'N', your task is to help Ninja find its ‘NINJA BASE’.
Note :
You are not required to print anything explicitly. It has already been taken care of. Just implement the function.
Input Format :
The first line of input contains a ‘T’ number of test cases.
The first line of each test case contains an integer ‘N’ denoting the given number.
Output Format :
For each test case, return the smallest ‘NINJA BASE’.
Constraints :
1 <= T <= 10 ^ 4
3 <= N <= 10 ^ 6

Time Limit: 1 second  
Follow Up:
Can you do this in O(logN) time and constant space?
Sample Input 1 :
2
7
21
Sample Output 1 :
2
4
Explanation For Sample Input 1 :
Test Case 1 :

For the first test case, the given number is ‘7’ so we return ‘2’ as we can write ‘7’ = 2 ^ 2 + 2 ^ 1 + 2 ^ 0’. Thus, ‘7’ base ‘2’ is ‘1 1 1’ and 2 is the smallest such number.

Test Case 2 :

For the first test case, the given number is ‘21’ so we return ‘4’ as we can write ‘21 = 4 ^ 2 + 4 ^ 1 + 4 ^ 0’. Thus, ‘21’ base ‘4’ is ‘1 1 1’ and 4 is the smallest such number.
Sample Input 2 :
2
6
15
Sample Output 1 :
5
2
*/

#include <iostream>
#include <vector>
using namespace std;

int ninjaBase(int n)
{
    // Write your code here
    int ans = 0;

    // Starting from smallest number iterating upto the given number.
    for (int i = 2; i < n; i++)
    {
        int temp = n;
        bool flag = true;

        while (temp > 0)
        {
            // If remainder on dividing is '1'
            if (temp % i == 1)
            {
                temp = temp / i;
            }

            // If remainder is not '1'
            else
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
        {
            ans = i;
            break;
        }
    }

    return ans;
}

class Runner
{
    int t;
    vector<int> arr;

public:
    void takeInput()
    {
        cin >> t;
        arr.resize(t);
        for (int c = 0; c < t; c++)
        {

            cin >> arr[c];
        }
    }

    void execute()
    {
        vector<int> arrCopy = arr;

        for (int i = 0; i < t; i++)
        {
            int ans = ninjaBase(arrCopy[i]);
        }

        arrCopy.clear();
    }

    void executeAndPrintOutput()
    {

        for (int i = 0; i < t; i++)
        {
            int ans = ninjaBase(arr[i]);

            cout << ans << "\n";
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
