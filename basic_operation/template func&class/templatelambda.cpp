#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    auto show = []<class T>(T *array, int size)
    {
        for (auto k = 0; k < size; k++)
        {
            cout << array[k] << " ";
        }
        cout << endl;
    };
    int nums[] = {1, 3, 5, 7};
    char symbs[] = {'A', 'B', 'C'};
    show(nums, 4);
    show(symbs, 3);
    return 0;
}
