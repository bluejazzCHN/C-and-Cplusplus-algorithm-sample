/*
Author by bluejazzchn
问题描述：农场主养了若干奶牛，想知道那些奶牛的奶产量比比较平均？那些奶牛的奶产量小于这头牛，那些奶牛大于这头牛？
问题分析：知道所有奶牛的产奶量，更具产年量找到产奶量的中位数/平均数。
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    // 产奶量数组
    float milk_amount[] = {10, 13, 8, 9.8, 4.7, 12.6, 14};
    // 计算奶牛数量
    int cow_num = sizeof(milk_amount) / sizeof(milk_amount[0]);
    // 按照有小到大排序
    sort(milk_amount, milk_amount + cow_num);
    // 显示奶牛数量
    cout << "cow's number： " << cow_num << endl;
    // 显示排序后的产奶量
    int i = 1;

    for (float c : milk_amount)
    {
        cout <<  i << ":" << c << ", ";
        i++;
    }

    nth_element(milk_amount, milk_amount + int(cow_num / 2), milk_amount + 7);
    cout << endl;
    cout << "Mid of milk production: " << milk_amount[int(cow_num / 2)] << endl;

    return 0;
}
