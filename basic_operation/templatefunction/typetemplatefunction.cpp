//演示template function的重载override
#include <iostream>

using namespace std;

class MyClass
{
public:
    int number;
    MyClass(int n)
    {
        number = n;
    }

    void show()
    {
        cout << "The object of class  MyClass: " << number << endl;
    }
};

//通用类型的模板方法
template <class X>
void show(X arg)
{
    cout << "The function argument: " << arg << endl;
}

//Integer类型的模板方法
template <>
void show<int>(int arg)
{
    cout << "The integer arument: " << arg << endl;
}

//特定类 MyClass 类型的模板方法
template <>
void show<MyClass>(MyClass obj)
{
    obj.show();
}

int main(int argc, char const *argv[])
{
    MyClass obj(300);
    show('A');
    show(100.0);
    show(200);
    show(obj);
    return 0;
}
