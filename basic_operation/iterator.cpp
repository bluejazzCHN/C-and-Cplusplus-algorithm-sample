#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void show(int);

int main(int argc, char const *argv[])
{
    //output iterator and copy usage
    int a[] = {10,20,30,40,50};
    ostream_iterator<int> out_it(cout,"|");
    copy(a,a+5,out_it);

    //back_insert iterator usage
    vector<int> v1(2,10),v2(3,20),v3(2,30);
    deque<int> q1(2,10),q2(3,20);

    back_insert_iterator<vector<int>> back_it(v1);
    copy(v2.begin(),v2.end(),back_it);
    cout << "\nBack iterator: ";
    for_each(v1.begin(),v1.end(),show);
    
    insert_iterator<vector<int>> ins_it(v1,v1.begin()+2);
    copy(v3.begin(),v3.end(),ins_it);
    cout << "\nInsert iterator: ";
    for_each(v1.begin(),v1.end(),show);

    front_insert_iterator<deque<int>> front_it(q1);
    copy(q2.begin(),q2.end(),front_it);
    cout<<"\nFront iterator: ";
    for_each(q1.begin(),q1.end(),show);

    return 0;
}

void show(int k){
    cout<< k << " ";
}
