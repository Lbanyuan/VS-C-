
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int card, loc, All[52];
    char huase[4] = { 'S','H','D','C' };
    char number[13][3] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
    srand(time(0));
    for (int i = 0; i < 52; i++)
    {
        All[i] = 0;
    }
    for (card = 1; card < 52; card++)
    {
        loc = rand() % 52;
        while (All[loc] != 0)
        {
            loc = rand() % 52;
        }
        All[loc] = card;
    }
    cout << "Play1" << '\t' << "Play2" << '\t' << "Play3" << '\t' << "Play4" << endl;
    for (int i = 0; i < 52; i++)
    {

        cout << huase[(All[i]) / 13] << " " << number[(All[i]) % 13] << '\t';
        if (i % 4==3)
        {
            cout << endl;
        }
    }
    return 0;
}
