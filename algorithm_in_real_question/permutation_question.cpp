#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res; // 全排序的结果集
vector<int> track;       // 一条回溯路径回溯路径

// 路径：记录在track对象中
// 路径元素选择列表：nums中不在track中的
// 结束条件：nums的元素全部在track中存在
void backtrack(vector<int> nums, vector<int> track)
{
    // 出发结束条件，结束条件：判断track是否已经完成遍历
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

        // 做选择，将n保存在track中
        track.push_back(n); // 加入track
        // 进入下一层决策
        backtrack(nums, track);
        // 取消选择，将n移除从track中
        track.pop_back(); // 清空track
    }
}
int main(int argc, char const *argv[])
{
    vector<int> a = {6, 2, 3, 1, 0};
    
    //对a按照由小到大排序
    // sort(a.begin(),a.end());
    //对a按照由大到小排序
    sort(a.begin(), a.end(), greater());

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
