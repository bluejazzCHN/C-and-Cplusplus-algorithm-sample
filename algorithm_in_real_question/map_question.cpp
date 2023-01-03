#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Student
{
private:
    int code;
    string name;
    float grd;

public:
    Student(int c, string n, float g) : code(c), name(n), grd(g) {}
    Student() : code(0), name("None"), grd(0) {}
    friend bool operator<(const Student &s1, const Student &s2);
    void show() const { cout << "C:" << code << " N:" << name << " G:" << grd << endl; }
};

void display(const Student &s);

int main(int argc, char const *argv[])
{
    //use set() to store the data.
    set<Student> s;
    s.insert(Student(200, "two", 3.5));
    s.insert(Student(100, "one", 2.5));
    s.insert(Student(300, "one", 4.5));

    for_each(s.begin(), s.end(), display);

    //use map() to store the data.
    map<int,Student,greater<int>> m;
    m[100]=Student(100,"one",3.5);
    m[200]=Student(200,"two",4.5);
    m[300]=Student(300,"three",2.5);

    map<int,Student,greater<int>>::iterator it;
    it = m.find(500);
    if(it!=m.end()) it->second.show();
    else cout << "Not found\n";

    for(it = m.begin();it!=m.end();++it)
    {
        it->second.show();
    }

    return 0;
}

bool operator<(const Student &s1, const Student &s2)
{
    if (s1.grd < s2.grd)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display(const Student& s)
{
    s.show();
}
