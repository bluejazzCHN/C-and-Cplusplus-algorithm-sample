/*
Author: bluejazzCHN
Question:
    Consists of 4 digit combination lock, each turn a bit,
    the minimum number of rotation of the specified password.
Analysis:
    There are two possibilities for each rotation, which can
    happen in any one of the four positions, so there are eight
    possibilities. For example, if you rotate one digit
    from 0000, you can get the following result:
    1000, 9000, 0100, 0900, 0010, 0090, 0001, 0009.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

string plusOne(string number, int j)
{
    string s = number;//"0009"
    if (s[j] == '9')
    {
        s[j] = '0';
    }
    else
    {
        s[j] += 1;
    }
    return s;
}
string minusOne(string number, int j)
{
    string s = number;//"0009"
    if (s[j] == '0')
    {
        s[j] = '9';
    }
    else
    {
        s[j] -= 1;
    }
    return s;
}

int openLock(vector<string> deadends, string target)
{
    set<string> deads;
    for (string s : deadends)
        deads.insert(s);

    set<string> visited;
    queue<string> q;
    int step = 0;

    q.push("0000");
    visited.insert("0000");

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            string cur = q.front();
            q.pop();

            if (deads.count(cur) != 0)
                continue;

            if (cur == target)
            {
                cout << "Vistited lock numbers are:" << endl;
                for (string str : visited)
                {
                    // cout << str << endl;
                }
                return step;
            }

            for (int j = 0; j < 4; j++)
            {
                string up = plusOne(cur, j);
                if (visited.count(up) == 0)
                {
                    q.push(up);
                    visited.insert(up);
                }
                string down = minusOne(cur, j);
                if (visited.count(down) == 0)
                {
                    q.push(down);
                    visited.insert(down);
                }
            }
        }
        step++;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    // unit test for every function
    // cout << plusOne("4009", 3) << endl;
    // cout << minusOne("4000", 3) << endl;

    vector<string> deadlocks = {"3000"};
    cout << openLock(deadlocks, "0031") << endl;
    return 0;
}
