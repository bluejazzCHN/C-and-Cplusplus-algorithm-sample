#include <iostream>

using namespace std;

class MyClass
{
public:
    char code;
    MyClass *next;
    ~MyClass()
    {
        cout << endl
             << "The object with the field " << code << " is deleted" << endl;
    }

    void show()
    {
        cout << code << " ";
        if (next)
        {
            next->show();
        }
    }
};

void deleteAll(MyClass *q)
{
    if (q->next)
    {
        deleteAll(q->next);
    }
    delete q;
}

int main(int argc, char const *argv[])
{
    auto n = 10;
    MyClass *pnt = new MyClass;
    pnt->code = 'A';

    MyClass *p;

    p = pnt;

    for (int k = 1; k <= n; k++)
    {
        p->next = new MyClass;
        p->next->code = p->code + 1;
        p = p->next;
    }

    p->next = 0;

    pnt->show();
    deleteAll(pnt);
    return 0;
}
