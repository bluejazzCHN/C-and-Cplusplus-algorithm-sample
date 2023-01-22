#include <iostream>

using namespace std;

template <class X>
class BaseClass
{
private:
    X value;

public:
    BaseClass(X val)
    {
        set(val);
    }
    void set(X val)
    {
        value = val;
    }
    X get()
    {
        return value;
    }
};

class Alpha : public BaseClass<int>
{
public:
    Alpha() : BaseClass<int>(0) {}
};

class Bravo : public BaseClass<char>
{
public:
    Bravo(char s) : BaseClass<char>(s) {}
};

int main(int argc, char const *argv[])
{
    Alpha objA;
    cout << "The object objA: " << objA.get() << endl;
    objA.set(1000);
    cout << "The object objA: " << objA.get() << endl;
    Bravo objB('A');
    cout << "The object objB: " << objB.get() << endl;
    objB.set('B');
    cout << "The object objB: " << objB.get() << endl;
    return 0;
}
