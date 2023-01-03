/*
Author by bluejazzchn
问题描述：有三种面值硬币{1,2,5}，任意给出总数，找到最少需要几枚硬币能够凑出这个总数。
问题分析：最优问题。状态变化就是没选择一个面值，amount-面值的变化。穷举减去不同面值，直至amount=0(返回有效次数)，或<0(无解)
*/
#include <iostream>
#include <vector>

using namespace std;
static int total_recursive = 0;

const static vector<int> coins = {1, 2, 5}; //硬币面值

int coinChange(const vector<int> &coin, int amount)
{
    static vector<int> dp(amount, 0); //递归剪枝数组
    int res = amount;
    for (int i = 0; i < coins.size(); i++)
    {
        ++total_recursive;
        if ((amount - coins[i]) < 0)
            continue;
        if (dp[amount - coins[i]] == 0)
            dp[amount - coins[i]] = coinChange(coins, amount - coins[i]);
        res = min(res, 1 + dp[amount - coins[i]]); // 递归剩下的amount最少硬币
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int amount = 0;
    cout << "Please input amount:";
    cin >> amount;
    cout
        << "Coins total: " << coinChange(coins, amount) << " "
        << "Recruitive total: " << total_recursive << endl;

    return 0;
}
