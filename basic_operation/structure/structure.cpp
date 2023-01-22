#include <iostream>

using namespace std;

struct MyMoney
{
    string name;
    double money;
    double rate;
    int time;
};

double getMoney(MyMoney m)
{
    double s = m.money;
    for (auto k = 1; k <= m.time; k++)
    {
        s *= (1 + m.rate / 100);
    }
    return s;
}

void show(MyMoney m)
{
    cout << "The name: " << m.name << endl;
    cout << "The initial amount: " << m.money << endl;
    cout << "The annual rate: " << m.rate << endl;
    cout << "The term (in years): " << m.time << endl;
    cout << "The final ammount: " << getMoney(m) << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    MyMoney cat = {"Tome the cat", 1000, 8, 5};
    MyMoney mouse = {"Jerry the mouse", 1200, 7, 4};
    show(cat);
    show(mouse);
    return 0;
}
