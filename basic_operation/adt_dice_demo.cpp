#include <iostream>
#include <vector>

using namespace std;

class Dice
{
private:
    int total = 0;
    int diceNumbers;
    vector<int> tosses;
    string name;

public:
    Dice(int num, string n)
    {
        if (0 < num)
        {
            name = n;
            diceNumbers = num;
            vector<int> v = vector<int>(num, 0);
            tosses = vector<int>(v);
        }
        else
        {
            cout << "num is greater than 0." << endl;
        }
    };
    void displayToss()
    {
        cout << "Toss total is " << total << endl;
        cout << "  | " << endl;
        for (int i = 0; i < diceNumbers; i++)
        {
            cout << "  | -- "
                 << "No " << i << " dice's number is " << tosses[i] << endl
                 << endl;
        }
    };
    void toss()
    {
        total = 0;
        for (int i = 0; i < diceNumbers; i++)
        {
            tosses[i] = 1 + rand() % 6;
            total = total + tosses[i];
        }
    };
    string getWinner(Dice *d)
    {
        string winner = "No winner";
        if (total > d->total)
        {
            winner = name;
        }
        else if (total < d->total)
        {
            winner = d->name;
        }
        return winner;
    }
};

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Dice *robin = new Dice(4, "robin");
    robin->toss();
    robin->displayToss();
    Dice *father = new Dice(4, "father");
    father->toss();
    father->displayToss();
    cout << endl;
    cout << "Winner is " << robin->getWinner(father) << endl
         << endl;
    return 0;
}
