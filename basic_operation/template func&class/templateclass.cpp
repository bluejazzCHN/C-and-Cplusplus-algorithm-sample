#include <iostream>

using namespace std;

template <class A, class B>
class MyClass
{
public:
    A first;
    B second;
    MyClass(A f, B s)
    {
        first = f;
        second = s;
    }
    void show()
    {
        cout << "The first field: " << first << endl;
        cout << "The second field: " << second << endl;
    }
};

int main(int argc, char const *argv[])
{
    MyClass<int, char> objA(100, 'A');
    MyClass<string, double> objB("test", 10.5);
    MyClass<char *, string> objC((char *)"first", "second");
    MyClass<int, int> objD(1, 2);
    objA.show();
    objB.show();
    objC.show();
    objD.show();
    return 0;
}
