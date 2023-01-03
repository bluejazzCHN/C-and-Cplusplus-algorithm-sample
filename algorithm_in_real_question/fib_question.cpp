#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int fib(int n)
{
    vector<int> memo(n + 1, 0);
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (memo[n] != 0)
        return memo[n];
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int fib_dp(int n)
{
    vector<int> dp(n+1, 0);

    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;


    dp[1] = dp[2] = 1;

    for (int i = 3; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    clock_t start, end;
    start = clock();
    cout << fib(3) << endl;
    cout << fib(5) << endl;
    end = clock();
    cout << "time = " << double(end - start) / 1000 << "s" << endl; // 输出时间（单位：ｓ）
    start = clock();
    cout << fib_dp(3) << endl;
    cout << fib_dp(6) << endl;
    end = clock();
    cout << "time = " << double(end - start) / 1000 << "s" << endl; // 输出时间（单位：ｓ）

    return 0;
}
