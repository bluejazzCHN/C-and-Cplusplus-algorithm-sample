#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int batch;
    cout << "Transaction batch:";
    cin >> batch;
    while (batch--)
    {
        map<string, map<string, int>> fruit;
        int transaction;
        cout << "How many transaction will be entered?";
        cin >> transaction;
        for (auto i = 0; i < transaction; i++)
        {
            string name, place;
            int num;
            cout << "Input fuit transaction info:"
                 << "\n";
            cin >> name >> place >> num;
            fruit[place][name] += num;
        }

        map<string, map<string, int>>::iterator outer_it;
        map<string, int>::iterator inner_it;

        for (outer_it = fruit.begin(); outer_it != fruit.end(); outer_it++)
        {
            cout << outer_it->first << endl;
            for (inner_it = outer_it->second.begin(); inner_it != outer_it->second.end(); inner_it++)
            {
                cout << "   |----" << inner_it->first << "(" << inner_it->second << ")" << endl;
            }
        }
    }
    return 0;
}
