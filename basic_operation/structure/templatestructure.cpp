#include <iostream>

using namespace std;

template <class A, class B>
struct MyStruct
{
    A first;
    B second;
};

template <class A, class B>
void show(MyStruct<A, B> m)
{
    cout << "The first field: " << m.first << endl;
    cout << "The second field: " << m.second << endl;
}

int main(int argc, char const *argv[])
{
    MyStruct<int, char> strA = {100, 'A'};
    MyStruct<double, string> strB = {2.5, "text"};
    show(strA);
    show(strB);
    return 0;
}
