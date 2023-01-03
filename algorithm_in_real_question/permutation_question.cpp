#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res; // 保存排序结果
vector<int> track;       // 回溯路径，完整的track结果会保存在res中。完整track条件为track的size等于nums的size。

void backtrack(vector<int> nums, vector<int> track)
{
    // 判断track是否已经完成遍历
    if (track.size() == nums.size())
    {
        res.push_back(track);
        return;
    }

    for (int n : nums)
    {
        // 判断n是否已经在track中
        if (count(track.begin(), track.end(), n))
        {
            continue;
        }
        track.push_back(n); // 加入track
        backtrack(nums, track);
        track.pop_back(); // 清空track
    }
}
int main(int argc, char const *argv[])
{
    vector<int> a = {1, 2, 3, 6};

    // 回溯，得出a的全排列结果保存在res中。
    backtrack(a, track);

    // 显示回溯结果
    for (int i = 0; i < res.size(); i++)
    {
        cout << "Permutation No " << i + 1 << ":" << endl;
        cout << " | {";
        for (int n : res[i])
        {
            cout << n << ",";
        }
        cout << "}" << endl;
        ;
    }
    return 0;
}
