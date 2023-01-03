#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student
{
    int code;
    string name;
    float grd;
};

/* sort functions used to customize data type in sort()*/
bool operator<(const Student &s1, const Student &s2);
bool name_sort(const Student &s1, const Student &s2);

int main(int argc, char const *argv[])
{
    int *p, arr[] = {30, 20, 10, 40, 50};
    sort(arr, arr + 4);
    p = find(arr, arr + 5, 30);
    if (p != arr + 5)
    {
        cout << "Element " << *p << " found in position " << p - arr + 1 << "\n";
    }
    else
    {
        cout << "Element not found\n";
    }

    Student s[3] = {{10, "C", 3.5}, {20, "A", 2.5}, {30, "B", 4.5}};
    vector<Student> v;

    for (int i = 0; i < 3; i++)
    {
        v.push_back(s[i]);
    }
    // sort by grd using operator< function1
    sort(v.begin(), v.end());
    cout << "Order by grd:" << endl;
    
    for (int i = 0; i < 3; i++)
    {
        cout << v[i].code << " " << v[i].name << " " << v[i].grd << "\n";
    }

    // sort by name using name_order function
    sort(v.begin(), v.end(), name_sort);
    cout << "Order by name:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << v[i].code << " " << v[i].name << " " << v[i].grd << "\n";
    }

    return 0;
}

/*customer data type, must implement "operator<"*/

bool operator<(const Student &s1, const Student &s2)
{
    if (s1.grd < s2.grd) /* If we want to sort in descending order, one way
     is to write if(s2.grd < s1.grd). */
        return true;
    else
        return false;
}

bool name_sort(const Student &s1, const Student &s2)
{
    if (s1.name < s2.name)
    {
        return true;
    }
    else
    {
        return false;
    }
}