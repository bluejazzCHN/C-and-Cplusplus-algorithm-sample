#include <iostream>

using namespace std;

template <class T>
void show(T arg)
{
    cout << arg << endl;
}

template <class T>
void show(T *m, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
}

template <class T>
void sort(T *m, int n)
{
    show(m, n);

    T s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (m[j] > m[j + 1])
            {
                s = m[j + 1];
                m[j] = m[j + 1];
                m[j] = s;
            }
        }
    }
    show(m, n);
}

int main(int argc, char const *argv[])
{
    show('A');
    show(123);
    show("String");

    int A[5] = {3, 2, 8, 1, 0};
    char B[7] = {'Z', 'B', 'Y', 'A', 'D', 'C', 'X'};
    sort(A, 5);
    sort(B, 7);
    return 0;
}
